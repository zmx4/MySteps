#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;
	cin >> n;
	unordered_map<int, int> frequency;
	for (int i = 0;i < n;i++)
	{
		int a;
		cin >> a;
		frequency[a]++;
	}
	pair<int, int> max_frequency = {0, 0};
	for (const auto &pair : frequency)
	{
		if(pair.second > max_frequency.second)
		{
			max_frequency = pair;
		}
	}
	cout<<max_frequency.first<<' '<<max_frequency.second<<endl;
		return 0;
}