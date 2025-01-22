#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	// Sort the array
	sort(a.begin(), a.end());

	// Initialize the minimum range difference
	long long min_diff = LLONG_MAX;

	// Use two pointers to find the minimum range difference after doubling a subarray
	for (int i = 0, j = 0; j <= n; ++j)
	{
		if (j < n && a[j] * 2 > a[i])
		{
			continue;
		}
		// Calculate the new max and min values after doubling the subarray [i, j-1]
		long long new_max = max((long long)a[n - 1], a[j - 1] * 2);
		long long new_min = min((long long)a[0] * 2, a[i]);
		min_diff = min(min_diff, new_max - new_min);
		i++;
	}

	cout << min_diff << endl;
	return 0;
}
