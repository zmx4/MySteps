#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int b[100][100];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for(int j = 0;j < n;j++)
	{
		int min = 1000;
		for(int i = 0;i < n;i++)
		{
			if(a[i][j] < min)
			{
				min = a[i][j];
			}
		}
		for(int i = 0;i < n;i++)
		{
			if(a[i][j] == min)
			{
				b[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		int maxVal = INT_MIN;
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] > maxVal)
			{
				maxVal = a[i][j];
			}
		}
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] == maxVal)
			{
				++b[i][j];
			}
		}
	}

	int sign = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(b[i][j]==2)
			{
				cout << i << " " << j << endl;
				sign = 1;
			}
		}
	}
	if(sign==0)
	{
		cout << "NONE" << endl;
	}
	return 0;
}