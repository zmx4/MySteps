#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> b(n);

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}

		vector<int> sorted_indices(n);
		for (int i = 0; i < n; i++)
			sorted_indices[i] = i;
		sort(sorted_indices.begin(), sorted_indices.end(), [&](const int &x, const int &y) -> bool
			{ return a[x] > a[y]; });

		sort(b.begin(), b.end(), greater<int>());

		
		vector<int> score_to_problem(n);
		for (int i = 0; i < n; i++)
		{
			score_to_problem[sorted_indices[i]] = b[i];
		}

		for (int i = 0; i < n; i++)
		{
			cout << score_to_problem[i];
			if (i != n - 1)
				cout << " ";
		}
		cout << '\n';
	}

	return 0;
}