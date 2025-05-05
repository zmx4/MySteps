#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	int n;
	cin >> n;
	string l1, l2;
	cin >> l1 >> l2;
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int cur = (l1[i] - 'a' + cnt) % 26;
		int tar = l2[i] - 'a';
		if(cur==tar)continue;
		int diff = (tar - cur + 26) % 26;
		ans++;
		cnt = (cnt + diff) % 26;
	}
	cout << ans << endl;
	return 0;
}