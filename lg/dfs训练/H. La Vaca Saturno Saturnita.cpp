#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
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

		for (int j = l; j <= r; j++)
		{
			while (k % a[j] == 0)
			{
				k /= a[j];
			}
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
	while(T--)
	{
		solve();
	}
	
	return 0;
}