#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	double price;
	cin >> N >> price;
	while (N--)
	{
		double a = 0;
		cin >> a;
		if (a < price)
			printf("On Sale! %.1f\n", a);
	}
}