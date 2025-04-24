#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int N = 1e5+10;
int a[N],b[N],c[N],r[N];
int n,m;
void op1()
{
	bool found = false;
	int l1;cin>>l1;
	for(int i = 1;i <= l1;i++)cin>>c[i];
	int l2;cin>>l2;
	for(int i = 1;i <= l2;i++)cin>>r[i];
	for(int i = 1;i <= n - l1 + 1;i++)
	{
		int ii = i;
		
		if(a[ii]==c[1])
		{
			int j = 1;
			while(a[ii]==c[j])
			{
				ii++,j++;
				if(j==l1)
				{
					found = true;
					break;
				}
			}
		}
		if(found)
		{
			
			int j = 1;
			for(;j < i;j++)b[j]=a[j];
			int tmp = j,k = 1;
			for(;k<=l2;k++,j++)b[j]=r[k];
			ii++;
			for(;ii<=n;j++,ii++)b[j]=a[ii];
			int o = 1;
			for(;o < N;o++)a[o]=b[o],b[o]=0;
			n = n-l1+l2;
			return;
		}
	}
}
void op2()
{
	for(int i = 1;i < n;i++)
	{
		if((a[i]+a[i+1])%2==0)
		{
			b[i]=(a[i]+a[i+1])/2;
		}
	}
	int cnt = 1;
	for(int i = 1;i <= n;i++)
	{
		if(b[i]==0)
		{
			c[cnt] = a[i];
			cnt++;
		}
		else
		{
			c[cnt] = a[i];
			cnt++;
			n++;
			c[cnt]=b[i];
			cnt++;
		}
	}
	for(int i = 1;i <= N;i++)
	{
		a[i]=c[i];
		c[i]=0,b[i]=0;
	}
}
void op3()
{
	int l,r;cin>>l>>r;
	int mid = (l+r)/2;
	while(l<r)
	{
		swap(a[l],a[r]);
		l++,r--;
	}
}
signed main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	while(m--)
	{
		int op;cin>>op;
		if(op == 1)op1();
		if(op==2)op2();
		if(op==3)op3();
	}
	for(int i =1;i <= n;i++)
	{
		cout<<a[i];
		if(i!=n)cout<<" ";
	}
}
/*
6 1
1 2 3 4 5 6
1 
3 1 2 3
2 2 2 


*/