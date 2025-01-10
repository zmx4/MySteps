#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	int alice = 0, bob = 0;
	int maxNum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i]==a[i-1]&&a[i]==0)
		{
			b[i]=b[i-1]+1;
			maxNum = max(maxNum,b[i]);
		}
		if(a[i]==1)
		{
			alice++;
		}
		else
		{
			bob++;
		}
	}
	
	if(alice+maxNum>bob-maxNum)
	{
		cout << "Yes" << endl;
		
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}