#include<bits/stdc++.h> 
#define int long long
using namespace std;
using ll = long long;
const int N = 1e5+10;
int mod = 998244353;
ll fact(int n)
{
	if(n==0)return 1;
	int res = 1;
	for(int i = 2;i <= n;i++)
	{
		res *= i;
		res %= mod;
	}
	return res;
}
ll qpow(ll x,ll p)
{
	ll res = 1%mod;
	x%=mod;
	for(;p;p>>=1,x=x*x%mod)
	{
		if(p&1)res = res * x % mod;
	}
	return res;
}
signed main()
{
	int n;cin>>n;
	
	if(n < 3)
	{
		cout<<0<<endl;
		return 0;
	}
	if(n == 3)
	{
		cout<<6<<endl;
		return 0;
	}
	cout<<qpow(26,n-3)*6*(n+1)*n/2%mod<<endl;
	
	return 0;
}
