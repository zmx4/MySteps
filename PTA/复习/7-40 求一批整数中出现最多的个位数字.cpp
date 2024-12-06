#include <bits/stdc++.h>
using namespace std;

int a[20];
int maxNum = INT_MIN;

void process(int n)
{
	while (n)
	{
		a[n % 10]++;
		n /= 10;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		process(temp);
	}
	for(int i = 0; i < 10; ++i)
	{
		
		maxNum = max(maxNum, a[i]);
	}
	
	cout << maxNum << ":";
	for (int i = 0; i < 10; ++i)
	{

		if (a[i] == maxNum)
		{
			printf("%2d", i);
		}
	}
	return 0;
}