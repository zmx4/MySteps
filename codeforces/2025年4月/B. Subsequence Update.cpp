#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		int n, l, r;
		cin >> n >> l >> r;
		l--; // adjust l to 0-indexed

		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		// Create brr: arr[0:l] + sorted(arr[l:n]) in ascending order.
		vector<int> brr;
		// Keep the beginning part (unchanged)
		for (int i = 0; i < l; i++)
		{
			brr.push_back(arr[i]);
		}
		// Take the portion from index l to end and sort it (ascending order)
		vector<int> temp(arr.begin() + l, arr.end());
		sort(temp.begin(), temp.end());
		brr.insert(brr.end(), temp.begin(), temp.end());

		// Create crr: sorted(arr[0:r]) in descending order + arr[r:n]
		vector<int> crr;
		// Sort the first r elements in descending order
		vector<int> temp2(arr.begin(), arr.begin() + r);
		sort(temp2.begin(), temp2.end(), greater<int>());
		crr.insert(crr.end(), temp2.begin(), temp2.end());
		// Append the rest as is
		for (int i = r; i < n; i++)
		{
			crr.push_back(arr[i]);
		}

		// Sum from index l (inclusive) to index r (exclusive)
		long long sumB = 0, sumC = 0;
		for (int i = l; i < r; i++)
		{
			sumB += brr[i];
			sumC += crr[i];
		}

		cout << min(sumB, sumC) << "\n";
	}

	return 0;
}