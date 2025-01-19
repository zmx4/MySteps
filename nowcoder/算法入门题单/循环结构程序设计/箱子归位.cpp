#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int x, y;
	for (int i = 1; i <= 5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			int k;
			cin >> k;
			if(k==1)
			{
				x = i;
				y = j;
			}
		}
	}
	cout << abs(x - 3) + abs(y - 3) << endl;
	//cout<<x<<" "<<y<<endl;
	return 0;
}