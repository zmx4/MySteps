#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	long opponents, totalTime;
	cin >> opponents >> totalTime;
	long score[500001] = {0}, TargetScore[500001] = {0};
	long maxScore = 0;
	vector<ll>pre(500001, 0);
	for (int i = 0; i < opponents; i++)
	{
		cin >> score[i];
		// maxScore = max(score[i], maxScore);
	}
	// TargetScore = score;
	copy(begin(score), end(score), TargetScore);
	sort(TargetScore, TargetScore + opponents,greater<long>());
	for (int i = 0; i < opponents; i++)
	{
		pre[i + 1] = pre[i] + TargetScore[i];
	}
	long n = opponents, m = totalTime;
	long num = 0;
	for (int i = 0; i < n; i++)
	{
		if (m >= TargetScore[i])
		{
			m -= TargetScore[i];
			num++;
			maxScore = TargetScore[i];
		}
	}
	long rank = n + 1 - num;
	if (num < n)
	{
		if (score[num] <= maxScore || score[num] - maxScore <= m)
			rank--;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}