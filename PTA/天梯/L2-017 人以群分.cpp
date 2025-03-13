#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p.begin(), p.end());

	vector<int> outgoing, introverted;
	ll outgoing_sum = 0, introverted_sum = 0;

	int left = 0, right = n - 1;
	while (left < right)
	{
		outgoing.push_back(p[right]);
		outgoing_sum += p[right];
		right--;

		introverted.push_back(p[left]);
		introverted_sum += p[left];
		left++;
	}

	if (left == right)
	{
		outgoing.push_back(p[left]);
		outgoing_sum += p[left];
	}

	cout << "Outgoing #: " << outgoing.size() << endl;
	cout << "Introverted #: " << introverted.size() << endl;
	cout << "Diff = " << abs(outgoing_sum - introverted_sum) << endl;

	return 0;
}