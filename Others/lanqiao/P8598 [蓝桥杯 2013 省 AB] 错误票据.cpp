#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> s(10005,0);
	int x;
	while(cin>>x)
	{
		s[x]++;
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= 10004;i++)
	{
		if (s[i - 1] && s[i + 1] && !s[i])
			ans1 = i;
		if (s[i] > 1)
			ans2 = i;
		if (ans1 && ans2)
			break;
	}
	cout << format("{} {}", ans1, ans2) << endl;
	return 0;
}