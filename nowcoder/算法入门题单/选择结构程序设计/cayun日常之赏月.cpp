#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while(T--)
	{
		int a[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,1,2,3,4,5,6,7,8};
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= 29;i++)
		{
			if(a[i]==n&&a[i+1]==m)
			{
				cout << a[i + 2]<<endl;
				break;
			}
		}
	}

	return 0;
}