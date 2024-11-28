//24-11-28 Tick
#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
using namespace std;
const int N = 200005;
int a[N],b[N],c[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    while(t--)
    {
    	for(int i=0;i<=200005;i++)
    	{
    		c[i]=0;
    		// a[i]=0;
    		// b[i]=0;
    	}
    	int n,k;cin>>n>>k;
        int total = 0;
		for(int i=1;i<=k;i++)
        {
             cin>>a[i]>>b[i];
             c[a[i]]+=b[i];
             total = max(total,a[i]);
        }
		/*
    	for(int i=1;i<total+1;i++)
    	{
    		cout<<c[i]<<endl;
    	}
		*/
        sort(c + 1 ,c+total+1);
        int ans = 0;
		/*
    	for(int i=1;i<=total;i++)
    	{
    		cout<<c[i]<<endl;
    	}
		*/
        for(int i=total;i>total - n + 1;i--)
        {
          ans += c[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}
