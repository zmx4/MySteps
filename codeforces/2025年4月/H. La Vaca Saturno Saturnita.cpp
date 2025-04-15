#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int V_MAX = 100005;
#define int long long
map<int, vector<int>> factor;
vector<int> calcfactor(int n)
{
	vector<int> res;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			res.push_back(i);
			while(n % i == 0) n /= i;
		}
	}
	if(n > 1) res.push_back(n);
	return res;
}
vector<int> spf(V_MAX);
bool sieve_computed = false;
void sieve()
{
	if (sieve_computed)
		return;
	iota(spf.begin(), spf.end(), 0);
	for (int i = 2; i * i < V_MAX; i++)
	{
		if (spf[i] == i)
		{ // i 为质数
			for (int j = i * i; j < V_MAX; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
	sieve_computed = true;
}
map<int, int> getprimefactorization(int n)
{
	map<int, int> factors;
	if (n <= 1)
		return factors; // Handle n=1 case
	while (n > 1)
	{
		factors[spf[n]]++;
		n /= spf[n];
	}
	return factors;
}
map<int, map<int, int>> precomputed;
//
/*
function f(k, a, l, r):
ans := 0   for i from l to r (inclusive):
while k is divisible by a[i]:
k := k/a[i]
ans := ans + k
return ans
*/
/*
void solve()
{
	int n, q;cin>> n >> q;
	//cout<< n << " " << q << endl;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		if(factor.find(a[i]) == factor.end())
		{
			factor[a[i]] = calcfactor(a[i]);
		}
	}
	for(auto &x : factor)
	{
		sort(x.second.begin(), x.second.end());
	}
	for (int i = 0; i < q;i++)
	{
		int k, l, r;cin>>k>>l>>r;
		int ans = 0;
		vector<int>factork = calcfactor(k);
		for (int i = l; i <= r; i++)
		{
			if(binary_search(factork.begin(), factork.end(), a[i]))
			{
				k = k / a[i];
				ans += k;
			}
		}
		cout<<ans<<endl;
	}
}
*/
ll f(int k,int l,int r,const vector<int>& a)
{
	ll ans = 0;
	ll cur = k;
	for (int i = l; i <= r; i++)
	{
		int ai = a[i];
		// 从预处理得到 a[i] 的质因子分解
		const auto &pfai = precomputed[ai];
		// 计算能“除”多少次：m = min{ pfK[p] / pfai[p] } over p in pfai.
		int m = INT_MAX;
		bool canDivide = true;
		for (auto &pp : pfai)
		{
			int p = pp.first, exp_ai = pp.second;
			if (pfK.find(p) == pfK.end())
			{
				m = 0;
				canDivide = false;
				break;
			}
			else
			{
				m = min(m, pfK[p] / exp_ai);
			}
			if (m > 0)
			{
				// 除 m 次：curr = curr / (a[i]^m)
				// 这里直接用循环乘除即可，因为 a[i] 较小
				for (int j = 0; j < m; j++)
				{
					cur /= ai;
				}
				// 同时更新质因子分解 pfK
				for (auto &pp : pfai)
				{
					int p = pp.first, exp_ai = pp.second;
					pfK[p] -= m * exp_ai;
					if (pfK[p] == 0)
					{
						pfK.erase(p);
					}
				}
			}
			ans += cur;
			// 若当前 k 已等于1，则剩余区间每一步贡献1
			if (cur == 1 && i < r)
			{
				ans += (r - i);
				break;
			}
		}
	}
	return ans;
}
void solve()
{
	int n, q;
	cin >> n >> q;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < q; i++)
	{
		int k, l, r;
		cin >> k >> l >> r;
		int ans = 0;
		vector<int> factork = calcfactor(k);
		for (int j = l; j <= r; j++)
		{
			// while (k % a[j] == 0)
			// {
				// k /= a[j];
			// }
			// auto it = lower_bound(factork.begin(), factork.end(), a[j]);
			// if (it == factork.end() || *it != a[j])
			// {
				// continue;
			// }
			
			ans += k;
			if (k == 1 && j < r)
			{
				ans += (r - j);
				break;
			}
		}
		cout << ans << endl;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	sieve();
	while(T--)
	{
		solve();
	}
	
	return 0;
}