//25-1-25 Tick
#include <bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;

ll solve(int n)
{
	ll cnt=0;
	while(n){
		if(n&1) cnt++;
		n>>=1;
	}
	return cnt;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    ll T;
    cin>>T;
    while(T--)
    {
		ll n;
       	cin>>n;
        bitset<128>b(n);
    	ll ans = b.count();
    	cout<<ans<<" ";
    	ll ans2 = 1;
    	while (ans--)
    	{
    		ans2 *= 2;
    	}
    	cout<<ans2-1<<endl;
    }

    return 0;
}
