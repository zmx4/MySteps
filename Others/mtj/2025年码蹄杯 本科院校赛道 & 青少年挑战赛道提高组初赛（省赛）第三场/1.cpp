#include<bits/stdc++.h> 
#define int long long
using namespace std;
using ll = long long;
const int N = 5e5+10;
const int mod = 1e9+7;
using namespace std;
ll a[N],b[N];
ll persum[N],perxor[N];
signed main( )
{
	int n;cin>>n;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= n;i++)cin>>b[i];
	for(int i = 1;i <= n;i++)persum[i]=persum[i-1]+a[i];
	for(int i = 1;i <= n;i++)perxor[i]=perxor[i-1]^b[i];
	int ans = 0;
	for(int i = 1;i <= n;i++)
		for(int j = i;j <= n;j++)
		{
			ans=ans+(persum[j]-persum[i-1])*(perxor[j]^perxor[i-1])%mod;
		}
	
	cout<<ans<<endl;
	
	return 0;
}
