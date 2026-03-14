#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int adult = max(c, d);
	int child = min(c, d);

	if (c >= a && d >= a) 
	{
		printf("%d-Y %d-Y\n", c, d);
		printf("huan ying ru guan");
	}
	else if (c >= a && d < a)
	{
		if (c >= b)
		{
			printf("%d-Y %d-Y\n", c, d);
			printf("qing 1 zhao gu hao 2");
		}
		else
		{
			printf("%d-Y %d-N\n", c, d);
			printf("1: huan ying ru guan");
		}
	}
	else if (d >= a && c < a)
	{
		if (d >= b) 
		{
			printf("%d-Y %d-Y\n", c, d);
			printf("qing 2 zhao gu hao 1");
		}
		else 
		{
			printf("%d-N %d-Y\n", c, d);
			printf("2: huan ying ru guan");
		}
	}
	else
	{
		printf("%d-N %d-N\n", c, d);
		printf("zhang da zai lai ba");
	}

	return 0;
}