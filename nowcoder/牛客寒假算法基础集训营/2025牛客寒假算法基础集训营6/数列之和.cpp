#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int a(int n)
{
	return n + log2(n + log2(n));
}
void solve()
{
    ll n;cin>>n;
	if(n==1)cout<<2<<endl;
	else
	{
		ll res = n * 2;
		ll cnt = (ll)log2(res);
		res += (cnt - 1) * 2;
		if(res>=(1ll<<(cnt+1)))
			res += 2;
		cout<<res<<endl;
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