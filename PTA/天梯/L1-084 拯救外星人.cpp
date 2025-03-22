#include <bits/stdc++.h>
using namespace std;
int fact(int b)
{
	int a = 1.0;
	for (int i = 1; i <= b; i++)
	{
		a = a * i;
		// printf("%lf\n", a);
	}
	// printf("%lf\n",a);
	return a;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << fact(a + b);
}