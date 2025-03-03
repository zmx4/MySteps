#include <iostream>
#define endl "\n"
#define ll long long
using namespace std;
const ll N = 1000000;
int a[] = {1, 7, 49, 343, 2401, 16807, 117649, 823543};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	ll sum = 0;
	int i = 1;
	for (i = 1; sum <= N; i++)
	{
		for (int j = 1; j <= 5;j++)
		{
			sum += i;
			if(sum>=N)
				break;
		}
		if (sum >= N)
			break;
		i *= 7;
	}
	cout << i << " " << sum << endl;
	return 0;
}