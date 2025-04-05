#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 998244353;

ll quickmin(ll a, ll b, ll p = MOD) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
const int MAXN = 500000;
vector<ll> fact(MAXN + 1), invfact(MAXN + 1);
void init()
{
	fact[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	{
		fact[i] = fact[i - 1] * i % MOD;
	}
	invfact[MAXN] = quickmin(fact[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--)
	{
		invfact[i - 1] = invfact[i] * i % MOD;
	}
}
ll calc(const vector<int> &c, int target)
{
	vector<ll> dp(target + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < 26; i++)
	{
		int cnt = c[i];
		for (int j = target; j >= 0; j--)
		{
			if (j >= cnt)
				dp[j] = (dp[j] + dp[j - cnt]) % MOD;
		}
	}
	return dp[target];
}

void solve()
{
	vector<int> a(26, 0);
	for(int i = 0; i < 26; i++)cin >> a[i];
	ll sum = accumulate(a.begin(), a.end(), 0LL);
	int odd = (sum + 1) / 2, even = sum / 2;
	ll part = calc(a, 0);
	ll d = 1;
	for (int i = 0; i < 26; i++)
	{
		d = d * fact[a[i]] % MOD;
	}
	ll ans = 0;
	ans = ans * part % MOD;
	ans = ans * quickmin(d, MOD - 2, MOD) % MOD;
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
	init();
	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}