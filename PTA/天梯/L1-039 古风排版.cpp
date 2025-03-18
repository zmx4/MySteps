#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();
	string s;
	getline(cin, s);
	string ans[n];
	
	for(int i = 0; i < s.size();i++)
	{
		ans[i % n].push_back(s[i]);
	}
	for (int i = 0; i < n;i++)
	{
		if(ans[i].size()==ans[0].size())reverse(ans[i].begin(), ans[i].end());
		else
		{
			reverse(ans[i].begin(), ans[i].end());
			while (ans[i].size() != ans[0].size())
				ans[i]=' '+ans[i];
			
		}
	}
	for (int i = 0; i < n;i++)
	{
		cout << ans[i] << endl;
	}
		return 0;
}