#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N = 3e5+10;
int n,m;
int a[N],b[N];
short vis[N];
signed main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;i++)cin>>a[i];
	for(int i = 1;i <= m;i++)cin>>b[i];
	int idx1 = 1,idx2 = 1;
	for(int i = 1;i <= n;i++)
	{
		if(a[i]==b[idx1])
		{
			vis[i]=1;
			idx1++;
		}
		if(a[i]==b[idx2]&&vis[i]!=1)
		{
			vis[i]=2;
			idx2++;
		}
		if(idx1==m+1&&idx2==m+1)break;
	}
//	cout<<idx<<" "<<m<<endl;
	if(idx1 > m&&idx2>m)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
/*

6 3
1 2 2 2 2 3
1 2 3




*/
