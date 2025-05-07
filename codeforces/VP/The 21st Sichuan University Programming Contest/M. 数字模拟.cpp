#include <bits/stdc++.h>
#define endl endl
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
static const vector<vector<string>> digitPattern = {
	{"*****", "*...*", "*...*", "*...*", "*****"},
	{"....*", "....*", "....*", "....*", "....*"},
	{"*****", "....*", "*****", "*....", "*****"},
	{"*****", "....*", "*****", "....*", "*****"},
	{"*...*", "*...*", "*****", "....*", "....*"},
	{"*****", "*....", "*****", "....*", "*****"},
	{"*****", "*....", "*****", "*...*", "*****"},
	{"*****", "....*", "....*", "....*", "....*"},
	{"*****", "*...*", "*****", "*...*", "*****"},
	{"*****", "*...*", "*****", "....*", "*****"} 
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> grid(5);
	for (int i = 0; i < 5; i++)
	{
		getline(cin, grid[i]);
		if (grid[i].empty())
		{
			i--;
			continue;
		}
	}

	string ans;
	for (int d = 0; d < 3; d++)
	{
		int sc = d * 6;
		vector<string> block(5);
		for (int i = 0; i < 5; i++)
		{
			block[i] = grid[i].substr(sc, 5);
		}
		for (int num = 0; num < 10; num++)
		{
			if (block == digitPattern[num])
			{
				ans.push_back(char('0' + num));
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}