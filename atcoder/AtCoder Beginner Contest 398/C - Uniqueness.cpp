#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> A(n);
	unordered_map<ll, int> freq;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		freq[A[i]]++;
	}
	ll maxUnique = -1;
	int ansLabel = -1;
	for (int i = 0; i < n; i++)
	{
		if (freq[A[i]] == 1 && A[i] > maxUnique)
		{
			maxUnique = A[i];
			ansLabel = i + 1;
		}
	}
	cout << ansLabel << endl;
	return 0;
}