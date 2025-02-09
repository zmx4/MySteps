#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define int unsigned long long
using namespace std;

const int MAX_N = 100;
const int MAX_M = 1e4;

typedef struct ppower
{
	int base;
	int power;
} PP;

PP prime_powers;

int arr[MAX_M][MAX_M];

int prime[MAX_N + 5];

void init()
{
	prime_powers.base = 1;
	prime_powers.power = 1;
	for (int i = 2; i <= MAX_N; i++)
	{
		if (!prime[i])
			prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0]; j++)
		{
			if (i * prime[j] > MAX_N)
				break;
			prime[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}

// Get the smallest base and its corresponding power for x.
int get_base(int x)
{
	for (int i = 2; i <= MAX_N && i < x; i++)
	{
		int ans = 1;
		int temp = i;
		while (temp < x)
		{
			temp *= i;
			ans++;
			if (temp == x)
			{
				prime_powers.base = i;
				prime_powers.power = ans;
				return i;
			}
		}
	}
	prime_powers.base = x;
	prime_powers.power = 1;
	return x;
}

// Return the power corresponding to the last computed base.
// If the provided x matches the last computed base, then return the stored power.
// Otherwise, return -1.
int get_power(int x)
{
	if (x == prime_powers.base)
		return prime_powers.power;
	else
		return -1;
}

signed main()
{
	int ans = 0;
	init();

	// For numbers 1 to 100, compute their base and corresponding power.
	for (int i = 1; i <= 1000; i++)
	{
		int base = get_base(i);
		int power = get_power(base);
		printf("i: %d -> base = %d, power = %d\n", i, base, power);
	}

	// Process numbers from 2 to MAX_N.
	for (int i = 2; i <= MAX_N; i++)
	{
		int base = get_base(i);
		int power = get_power(base);
		for (int j = 2; j <= MAX_N; j++)
		{
			if (arr[base][power * j])
			{
				continue;
			}
			else
			{
				arr[base][power * j] = 1;
				ans++;
			}
		}
	}
	printf("ans = %d\n", ans);
	return 0;
}