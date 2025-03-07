#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const ll MOD = 1000000007;
long long modexp(long long base, long long exp, const long long &mod)
{
	long long result = 1;
	base = base % mod; // 处理 base 大于 mod 的情况
	while (exp > 0)
	{
		// 如果 exp 是奇数，将 base 乘到结果上
		if (exp % 2 == 1)
		{
			result = (result * base) % mod;
		}
		// exp 是偶数，将 base 平方并减少 exp 一半
		base = (base * base) % mod;
		exp = exp / 2;
	}
	return result;
}

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	ll cntW = 0;
	for (char c : s)
	{
		if (c == '?')
			cntW++;
	}

	if (n == 1)
	{
		if (s[0] == '?')
			cout << 2 << endl;
		else
			cout << 1 << endl;
		return;
	}

	ll cnt1 = 0, cnt2 = 0;
	if (s[0] == '?' && s[n - 1] == '?')
	{
		cnt1 = 2;
		cnt2 = 2;
	}
	else if ((s[0] == '?' && s[n - 1] != '?') || (s[0] != '?' && s[n - 1] == '?'))
	{
		cnt1 = 1;
		cnt2 = 1;
	}
	else
	{
		if (s[0] == s[n - 1])
		{
			cnt1 = 1;
			cnt2 = 0;
		}
		else
		{
			cnt1 = 0;
			cnt2 = 1;
		}
	}

	int edge = 0;
	if (s[0] == '?')
		edge++;
	if (s[n - 1] == '?')
		edge++;

	ll rem = cntW - edge;
	ll val = (cnt1 * (n - 2) + cnt2 * 2) % MOD;

	ll ans = (val * modexp(2, rem, MOD)) % MOD;

	cout << ans % MOD << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}