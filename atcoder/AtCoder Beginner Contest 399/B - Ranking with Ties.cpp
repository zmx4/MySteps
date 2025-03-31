#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end(), [](auto &p1, auto &p2)
		 { return p1.first > p2.first; });

	vector<int> rankRes(n);
	int currentRank = 1;
	for (int i = 0; i < n;)
	{
		int j = i;
		while (j < n && a[j].first == a[i].first)
		{
			j++;
		}
		for (int k = i; k < j; k++)
		{
			rankRes[a[k].second] = currentRank;
		}
		currentRank += (j - i);
		i = j;
	}

	for (int i = 0; i < n; i++)
	{
		cout << rankRes[i] << endl;
	}
	return 0;
}