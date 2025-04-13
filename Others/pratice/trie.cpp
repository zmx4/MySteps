#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

const int N = 100010;
int a[N][26],cnt[N],idx;
char str[N];

void insert(char str[])
{
	int p = 0;
	for (int i = 0;str[i];i++)
	{
		int u = str[i] - 'a';
		if (!a[p][u])
			a[p][u] = ++idx;
		p = a[p][u];
	}
	cnt[p]++;
}
int query(char str[])
{
	int p = 0;
	for (int i = 0; str[i];i++)
	{
		int u = str[i] - 'a';
		if(!a[p][u])
			return false;
		p = a[p][u];
	}
	return cnt[p];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	while(n--)
	{
		char op;
		cin >> op;
		if(op=='I')
		{
			cin >> str;
			insert(str);
		}
		if(op == 'Q')
		{
			cin >> str;
			cout << query(str) << endl;
		}
	}

	return 0;
}