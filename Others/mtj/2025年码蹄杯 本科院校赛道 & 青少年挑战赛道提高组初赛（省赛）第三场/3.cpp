#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N = 1e6+10;
int l[N],r[N];
signed main( )
{
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	int  ans  = 0;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	sort(a.begin()+1,a.end());
	int zuo = 0,you = 0;
	for(int i = 1;i <= n;i++)
	{
		if(a[i].first>zuo)
		{
			ans+=a[i].second-a[i].first+1;
			zuo = a[i].second;
		}
		else if(a[i].second>zuo)
		{
			ans+=a[i].second - zuo;
			zuo = a[i].second;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
1 2
2 3
5 6





*/
