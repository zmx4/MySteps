#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n,k;
    cin>>n>>k;
    vector<int> a(n),q(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        q[i]=q[i-1]+a[i-1];
    }
    int sum=INT_MAX,ans=0;
    for(int i=0;i+k<=n;i++)
    {
        if(q[i+k]-q[i]<sum)
        {
            sum=q[i+k]-q[i];
            ans=i+1;
        }
    }
    cout<<ans<<endl;

	return 0;
}