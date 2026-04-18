#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
signed main()
{
	int n;cin >> n;
	vector<int> a(n+1);
	int maxn = -1;
	map<int,int>pos;
	vector<int> ts;
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		maxn = max(maxn,a[i]);
		if(!pos.count(a[i]))
		{
			pos[a[i]]=i;
			ts.push_back(a[i]);
		}
	}
	bool flag = 0;
//	ts = a;
	sort(ts.begin(),ts.end());
	
	for(int i = 1;i <= n;++i)
	{
		if(a[i]==maxn)
		{
			if(flag)cout << " ";
			cout << i;
			flag = 1;
		}
	}
	cout << endl;
	int q;cin >> q;
	while(q--)
	{
		int x;cin >> x;
//		for(int i = 1;i <= n;++i)
//		{
//			if(a[i]>x)
//			{
//				cout << i << endl;
//				break;
//			}
//		}
		auto posi = upper_bound(ts.begin(),ts.end(),x);
		if(posi != ts.end())
		{
			cout << pos[*posi] << endl;
		}
		else 
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
