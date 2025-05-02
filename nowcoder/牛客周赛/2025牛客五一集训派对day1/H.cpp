#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	if (n == 2)
	{
		cout << "0111";
		return 0;
	}
	ll N = 1ULL << n;

	for (ll i = 0; i < N; i++)
	{
		int x = 0;
		for (ll j = i; j > 0; j >>= 1)
			x ^= (j & 1);
		cout << x;
	}

	return 0;
}