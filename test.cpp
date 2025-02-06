#include <iostream>
using namespace std;

const int MOD = 10007;

// Computes (base^exp) mod mod using fast exponentiation.
int modExp(int base, long long exp, int mod)
{
	long long result = 1;
	long long p = base % mod;
	while (exp)
	{
		if (exp & 1)
			result = (result * p) % mod;
		p = (p * p) % mod;
		exp >>= 1;
	}
	return (int)result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	int c;
	cin >> n >> c;

	// The number of valid colorings for a cycle is given by the formula:
	//   (c-1)^n + (-1)^n * (c-1)
	// Note that (-1)^n is 1 when n is even and -1 when n is odd.
	int term = modExp(c - 1, n, MOD);
	int result;
	if (n % 2 == 0)
	{
		result = (term + (c - 1)) % MOD;
	}
	else
	{
		result = (term - (c - 1)) % MOD;
		if (result < 0)
			result += MOD;
	}

	cout << result << "\n";
	return 0;
}