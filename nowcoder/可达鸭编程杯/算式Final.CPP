//24-11-23 Tick
#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
using namespace std;
const int mod = 1000000007;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int a[3000]={0};
    int sum=0;
	int cnt1=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    	if(a[i]==1)cnt1++;
    }
    sum=a[0];
    for(int i=1;i<n;i++)
    {
    	if(a[i]==1)sum++;
    	else if(a[i]*sum>a[i]+sum){sum*=a[i];}
		else {sum+=a[i];}
    	sum%=mod;
    }
	cout<<sum<<" ";
	sort(a,a+n);
	//cout<<cnt1<<" ";
	sum=cnt1;
	int cnt=0,sign = 0;
	for(int i=0;i<n;i++)
	{
		sum%=mod;
		if(a[i]==1)continue;
		if (a[i]!=1&&sign==0)
		{
			if (sum==0)sum++;
			if (a[i]*sum>a[i]+sum)sum*=a[i];
			else sum+=a[i];
			sign=1;
		}
		else if (a[i]*sum>a[i]+sum)sum*=a[i];
		else sum+=a[i];
		sum%=mod;
	}

	cout<<sum%mod;
    return 0;
}
