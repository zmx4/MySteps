#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int n;
int a[5];
vector<int> nums;
vector<int> squareSums;
ll cal(int n)
{
	ll sum = 0;
	while(n > 0)
	{
		ll digit = n % 10;
		sum += digit * digit;
		n /= 10;
	}
	return sum;
}

void gen()
{
	vector<int> perm;
	for (int i = 1; i <= n; i++)
	{
		perm.push_back(a[i]);
	}
	do
	{
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			num = num * 10 + perm[i];
		}
		nums.push_back(num);
		squareSums.push_back(cal(num));
	} while (next_permutation(perm.begin(), perm.end()));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);


	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);






	return 0;
}