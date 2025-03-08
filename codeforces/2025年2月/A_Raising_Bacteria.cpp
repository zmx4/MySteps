#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    ll x;cin>>x;
    ll ans = 0;
    while(x!=1)
    {
        if(x%2==1)
        {
            ans++;
            x/=2;
        }
        else
        {
            x/=2;
        }
    }
    cout<<ans+1<<endl;
	return 0;
}