#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define int long long
using ll = long long;
int f[200][200];
signed main()
{
	int n;
	vector<int>a;
	while(cin>>n)a.push_back(n);
	f[0][0]=0,f[1][0]=a[0];
	f[1][1]=a[1],f[0][1]=a[0];
	for(int i = 2;i < a.size();i++)
	{
		f[1][i]=max(f[1][i-2],f[0][i-1])+a[i];
		f[0][i]=max(f[0][i-1],f[1][i-1]);
	}
	cout<<max(f[0][a.size()-1],f[1][a.size()-1])<<endl;
	
}
