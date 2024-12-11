#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;cin>>n;
	vector<int> v(n);

	for(int i=0;i<n;++i)
		cin>>v[i];

	int police=0,crime=0;
	for (int i = 0;i < n;++i)
	{
		if(v[i]>0)
			police+=v[i];
		else if(v[i]<0)
		{
			if(police>0)
				police--;
			else
				crime++;
		}
	}
	cout<<crime<<endl;
		return 0;
}