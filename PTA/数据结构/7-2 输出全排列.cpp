#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n;i++)
		a[i] = i + 1;
	do
	{
		for(const int &i:a)
			cout << i;
		cout << endl;
	} while (next_permutation(a.begin(),a.end()));
	

		return 0;
}