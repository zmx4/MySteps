#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 1e6+10;

struct family
{
	int f = -1, m = -1;
	int sex = -1;
}fa[N];
int n, k, uns;
unordered_set<int> s;

void dfs(int x,int depth)
{
	if(depth>5)
		return;
	uns++;
	s.insert(x);
	if(fa[x].f!=-1)
		dfs(fa[x].f, depth + 1);
	if (fa[x].m != -1)
		dfs(fa[x].m, depth + 1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n;
	int id, f, mo;
	char se;
	for (int i = 0; i < n;i++)
	{
		cin >> id >> se >> f >> mo;
		if(se=='M')
			fa[id].sex= 1;
		else
			fa[id].sex = 0;
		fa[id].f = f;
		fa[id].m = mo;
#pragma region 仅作为关联出现
		if (f != -1)
			fa[f].sex = 1; // 设置父亲性别
		if (mo != -1)
			fa[mo].sex = 0; // 设置母亲性别
		fa[id].f = f;
		fa[id].m = mo;
#pragma endregion
	}
	cin >> k;
	while(k--)
	{
		int x, y;
		cin >> x >> y;
		uns = 0;
		s.clear();
		dfs(x, 1);
		dfs(y, 1);
		if(fa[x].sex==fa[y].sex)
			cout << "Never Mind" << endl;
		else if(uns == s.size())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}