#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	array<int, 9> a={1,2,3,4,5,6,7,8,9};
	do
	{
		int num1 = a[0] * 100 + a[1] * 10 + a[2];
		int num2 = a[3] * 100 + a[4] * 10 + a[5];
		int num3 = a[6] * 100 + a[7] * 10 + a[8];
		if (num1 * 2 == num2 && num1 * 3 == num3)
			cout << num1 << " " << num2 << " " << num3 << endl;
	} while (next_permutation(a.begin(), a.end()));



	return 0;
}