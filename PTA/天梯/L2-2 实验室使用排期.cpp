#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e3 + 10;
struct times
{
	int sth, stm, sts;
	int eth, etm, ets;
};
int toSec(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	times t[N];
	for (int i = 1;i <= n;i++)
	{
		cin >> t[i].sth;
		cin.ignore(1);
		cin >> t[i].stm;
		cin.ignore(1);
		cin >> t[i].sts;
		cin >> t[i].eth;
		cin.ignore(1);
		cin >> t[i].etm;
		cin.ignore(1);
		cin >> t[i].ets;
	}
	sort(t+1, t+n+1, [&](const times &a, const times &b)
		 {
        int endA = toSec(a.eth, a.etm, a.ets);
        int endB = toSec(b.eth, b.etm, b.ets);
        if(endA == endB){
            int startA = toSec(a.sth, a.stm, a.sts);
            int startB = toSec(b.sth, b.stm, b.sts);
            return startA < startB;
        }
        return endA < endB; });
		int cnt = 0;
		int curend = 0;
		for (int i = 1; i <= n;i++)
		{
			int start = toSec(t[i].sth, t[i].stm, t[i].sts);
			int end = toSec(t[i].eth, t[i].etm, t[i].ets);
			if (start >= curend)
			{
				cnt++;
				curend = end;
			}
		}
		cout << cnt << endl;
			return 0;
}