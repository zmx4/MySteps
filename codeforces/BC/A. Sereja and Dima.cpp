#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i)
		cin>>a[i];
	int s=0,d=0;
	int l = 0, r = n-1;
	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		if(a[l] > a[r])
		{
			if (flag)
				s += a[l];
			else
				d += a[l];
			l++;
			flag= !flag;
		}
		else
		{
			if (flag)
				s += a[r];
			else
				d += a[r];
			r--;
			flag=!flag;
		}
	}
	cout<<s<<" "<<d<<endl;
	return 0;
}