#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e6 + 10;
struct choco
{
	int m;
	int n;
};
bool judge(choco a,choco b)
{
	return a.m - a.n > b.m - b.n;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, K;
	cin >> n >> K;
	choco ch[N];
	for (int i = 0; i < n;i++)
		cin >> ch[i].m;
	for (int i = 0; i < n; i++)
		cin >> ch[i].n;
	sort(ch, ch + n, judge);
	int ans = 0;
	for (int i = 0; i < K;i++)
		ans += ch[i].m;
	for (int i = K; i < n; i++)
		ans += ch[i].n;
	cout << ans << endl;
	return 0;
}