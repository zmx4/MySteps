#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
const int lim = 2200;
vector<ll> t[N];
multiset<int> ms;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		int x, y;
		cin >> x >> y;
		t[x].push_back(i);
	}

	return 0;
}