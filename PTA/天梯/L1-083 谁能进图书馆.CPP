#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int adult = max(c, d);
	int child = min(c, d);

	if (adult >= b && child < a)
	{
		printf("%d-Y %d-Y\n", c, d);
		if (c > d)
		{
			printf("qing 1 zhao gu hao 2\n");
		}
		else
		{
			printf("qing 2 zhao gu hao 1\n");
		}
	}
	else if (adult >= b && child >= b)
	{
		printf("%d-Y %d-Y\n", c, d);
		printf("huan ying ru guan\n");
	}
	else if ((adult < b && adult > a) && child < a)
	{
		if (c > d)
		{
			printf("%d-Y %d-N\n", c, d);
			printf("1: huan ying ru guan\n");
		}
		else
		{
			printf("%d-N %d-Y\n", c, d);
			printf("2: huan ying ru guan\n");
		}
	}
	else if (adult < a && child < a)
	{
		printf("%d-N %d-N\n", c, d);
		printf("zhang da zai lai ba\n");
	}

	return 0;
}