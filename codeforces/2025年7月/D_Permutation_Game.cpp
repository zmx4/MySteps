#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define gcd __gcd
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;using ull = unsigned long long;using LL = long long;using ULL = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f,INF = 0x3f3f3f3f;
#define int long long


const int N = 2e5 + 10, M = 1e5 + 10;
int n, k, pb, ps;
int p[N], a[N];
bool vis[N];
inline void solve()
{
	cin >> n >> k >> pb >> ps;
    for (int i = 1; i <= n; i++)cin >> p[i];
    for (int i = 1; i <= n; i++)cin >> a[i];
    auto score = [=](int s)
    {
        memset(vis, 0, sizeof vis);
        ll ans = 0,pos = s;
        ll cur = 0;
        int r = k;
        while(r > 0 && !vis[pos])
        {
            vis[pos] = true;
            ans = max(ans,cur + r * a[pos] * 1ll);
            cur += a[pos];
            pos = p[pos];
            --r;
        }
        return ans;
    };
    ll sa = score(pb),sb = score(ps);
    if(sa>sb)
    {
        cout << "Bodya" << endl;
    }
    else if(sa<sb)
    {
        cout << "Sasha" << endl;
    }
    else
    {
        cout << "Draw" << endl;
    }
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
#if ONLINE_JUDGE
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
	int T = 1;	cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}