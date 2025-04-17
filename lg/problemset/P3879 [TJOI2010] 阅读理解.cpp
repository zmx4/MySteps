#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();
	unordered_map<string, set<int>> mp;
	string s;
	int nums = 0,words = 0;
	for (int i = 0; i < n;i++)
	{
		int x;
		cin >> x;
		for(int j = 0;j<x;j++)
		{
			string str;
			cin>> str;
			mp[str].insert(i+1);
		}
	}
	int m;
	cin >> m;
	while(m--)
	{
		string w;
		cin >> w;
		if (mp.find(w) != mp.end())
		{
			for (auto i : mp[w])
			{
				cout << i << " ";
			}
			cout << endl;
		}
		else
		{
			cout << endl;
		}
	}
	return 0;
}