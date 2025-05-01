#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

int main()
{
	int n, k, a;
	cin >> n >> k;
	a = (n - k) / 2;
	for (int i = 0; i < n; i++)
		cout << ((i + 1) % (a + 1) == 0);
	return 0;
}