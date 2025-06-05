#include <bits/stdc++.h>
#define endl "\n"

using ll = long long;
using ull = unsigned long long;
using LL = long long;
using ULL = unsigned long long;
using namespace std;

void solve()
{
	int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    bool ok = true;
    if((mp[-1]==0&&mp[1]!=0)||(mp[-1]!=0&&mp[1]==0))
    {
        ok = false;
    }
    if(ok)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
	
	
	
	
	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	 int T = 1;	//cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}