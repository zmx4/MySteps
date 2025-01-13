#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int N = 8, a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	do
	{
		for (int i = 0; i < N; i++)
			cout << a[i] << " ";
		cout << endl;
	} while (next_permutation(a, a + N));

	return 0;
}