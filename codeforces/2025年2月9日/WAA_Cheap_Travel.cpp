#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(b>=2*a)
    {
        cout<<n*a;
    }
    else
    {
        ll ans = 0;
        while(n>0)
        {
            if(n>=2 && m > 0)
            {
                n -= 2;
                ans += b;
                m--;
            }
            else if(n >= 1&& m > 0&& b < 2*a)
            {
                n--;
                ans+=b;
                m--;
            }
            else
            {
                n--;
                ans+=a;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}