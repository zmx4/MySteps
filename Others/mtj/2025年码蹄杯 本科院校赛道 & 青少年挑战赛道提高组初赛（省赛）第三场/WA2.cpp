#include<bits/stdc++.h> 
#define int long long
using namespace std;
using ll = long long;
const int N = 1e5+10;
int mod = 998244353;
vector<int>fac,invfac;
int n;
static ll qpow(ll x,ll p)
{
	ll res = 1%mod;
	x%=mod;
	for(;p;p>>=1,x=x*x%mod)
	{
		if(p&1)res = res * x % mod;
	}
	return res;
}
ll inv (ll x){return qpow(x,mod-2);}
void init()
{
	fac[0]=1;
	for(int i = 1;i <= N;i++)
	{
		fac[i]=fac[i-1]*i%mod;
	}
	invfac[N]=inv(fac[N]);
	for(int i = N - 1;i >= 0;--i)
	{
		invfac[i]=(invfac[i+1]*(i+1))%mod;
	}
}
ll C(int n,int m)
{
	if(n < m||m < 0)return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
ll A(int n,int m)
{
	if(n < m||m < 0)return 0;
	return fac[n]*invfac[n-m]%mod;
}

signed main()
{
//	init();
//	cin>>n;
//	if(n < 3)
//	{
//		cout<<0<<endl;
//		return 0;
//	}
//	ll ans = C(3,n)*6*A(26,n-3);
//	cout<<ans<<endl;
	
	
	
	
	
	return 0;
}
