#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string a;
	cin >> a;
	vector<int> value(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 'A' || a[i] == 'B')
		{
			if (a[i] == 'A')
				value[i] += 2;
			if (a[i] == 'B')
				value[i] += 1;
			if (i > 0)
			{
				if (a[i - 1] == a[i])
				{
					value[i] += 2;
				}
				else if (a[i - 1] == 'A' || a[i - 1] == 'B')
				{
					value[i] += 1;
				}
			}
			if (i < n - 1)
			{
				if (a[i + 1] == a[i])
				{
					value[i] += 2;
				}
				else if (a[i + 1] == 'A' || a[i + 1] == 'B')
				{
					value[i] += 1;
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if (a[i] == '(')
		{
			int j = a.find(')', i);
			if (j != string::npos)
			{
				for (int k = i + 1; k < j; k++)
				{
					if (a[k] == 'A')
						value[k] *= 2;
					if (a[k] == 'B')
						value[k] *= 2;
				}
				i = j;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += value[i];
	}
	cout << sum;
}