#include <bits/stdc++.h>
using namespace std;
int main()
{
	// int a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
	int sz[6][7] = {0};
	for (int i = 0; i < 6; i++)
	{
		int temp;
		cin >> temp;
		sz[i][temp]++;
	}

	int a;
	cin >> a;
	a -= 1;

	while (a--)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 6; j >= 0; j--)
			{
				if (sz[i][j] == 0)
				{
					sz[i][j] = 1;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 6; j >= 0; j--)
		{
			if (sz[i][j] == 0 && i != 5)
			{
				cout << j << " ";
				break;
			}
			else if (sz[i][j] == 0 && i == 5)
			{
				cout << j;
				break;
			}
		}
	}
}