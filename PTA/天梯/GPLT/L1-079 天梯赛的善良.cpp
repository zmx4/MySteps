#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int min = INT_MAX, minp = 0, max = 0, maxp = 0;
	while (n--)
	{
		int a;
		cin >> a;
		if (a < min)
		{
			min = a;
			minp = 1;
		}
		else if (a == min)
			minp++;
		if (a > max)
		{
			max = a;
			maxp = 1;
		}
		else if (a == max)
			maxp++;
	}
	printf("%d %d\n%d %d", min, minp, max, maxp);
}