#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	
	int cnt = 0;
	int maxNum = -1;
	int index = 0;
	for(int i = 1; i <= 7; i++)
	{
		int a,b;
		cin >> a >> b;
		if(a + b > maxNum)
		{
			maxNum = a + b;
			index = i;
		}
	}
	cout<<index<<endl;
	return 0;
}