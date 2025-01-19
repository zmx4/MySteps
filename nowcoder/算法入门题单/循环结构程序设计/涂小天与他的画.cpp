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
		int n;
		cin >> n;
		if(n==1)cout<<"*"<<endl;
		else
		{
			for(int i=1;i<=(n/2)+1;i++)
			{
				for(int j = n/2-i+1;j>0;j--)cout<<" ";
				for (int j = 1; j <= (2 * i) - 1; j++)cout << "*";
				cout << endl;
			}
			for(int i=(n/2);i>0;i--)
			{
				for(int j = n/2-i+1;j>0;j--)cout<<" ";
				for (int j = 1; j <= (2 * i) - 1; j++)cout << "*";
				cout << endl;
			}
		}
	}

	return 0;
}