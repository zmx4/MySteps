#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 100010;
int a[N][26], cnt[N], idx;
char str[N];
void insert(char str[])
{
	int p = 0;
	for (int i = 0; str[i];i ++)
	{
		int u = str[i] - 'a';
		if(!a[p][u])
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
			return 0;
		p = a[p][u];
	}
	return cnt[p];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while(n--)
	{
		char op[2];
		//scanf("%s%s", op, str);
		cin >> op >> str;
		if(op[0] == 'I')
			insert(str);
		else
			printf("%d\n", query(str));
	}

	return 0;
}