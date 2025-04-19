#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int cnt[N], a[N][26], idx;

void insert(char *s)
{
	int p = s[0]-'a';
	for(int i = 1; s[i]; i++)
	{
		if(!a[p][s[i]-'a'])
			a[p][s[i]-'a'] = ++idx;
		p = a[p][s[i]-'a'];
	}
	cnt[p]++;
}
int query(char *s)
{
	int p = s[0]-'a';
	for(int i = 1; s[i]; i++)
	{
		if(!a[p][s[i]-'a'])
			return 0;
		p = a[p][s[i]-'a'];
	}
	return cnt[p];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);










	return 0;
}