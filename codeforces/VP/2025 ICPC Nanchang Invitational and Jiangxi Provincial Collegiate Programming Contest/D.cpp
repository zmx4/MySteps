#include <bits/stdc++.h>
#define endl "\n"
#define forr(i, a, b) for (int i = a; i <= b; i++)
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

void solve()
{
    ll x, x1, x2, y, y1, y2, z, z1, z2, n, ans = -1;
    vector<pair<ll, ll>> vecx, vecy, vecz;
    cin >> n >> x >> y >> z;
    forr( i, 1, n ){
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        vecx.push_back( make_pair( min( x1, x2 ), max( x1, x2 ) ));
        vecy.push_back( make_pair( min( y1, y2 ), max( y1, y2 ) ));
        vecz.push_back( make_pair( min( z1, z2 ), max( z1, z2 ) ));
    }
    sort(vecx.begin(), vecx.end());
    sort(vecy.begin(), vecy.end());
    sort(vecz.begin(), vecz.end());
    priority_queue<ll,vector<ll>,greater<ll>> q;
    forr( i, 0, vecx.size() - 1 ){
        while( q.size() ){
            if( q.top() < vecx[i].first ){
                q.pop();
            } else{
                break;
            }
        }
        ans = max(ans, (ll)(q.size() + 1));
        q.push( vecx[i].second );
    }
    while( q.size() ){
        q.pop();
    }
    forr(i, 0, vecy.size() - 1)
    {
        while (q.size())
        {
            if (q.top() < vecy[i].first)
            {
                q.pop();
            }
            else
            {
                break;
            }
        }
        ans = max(ans, (ll)(q.size() + 1));
        q.push(vecy[i].second);
    }
    while (q.size()){
        q.pop();
    }
    forr(i, 0, vecz.size() - 1)
    {
        while (q.size())
        {
            if (q.top() < vecz[i].first)
            {
                q.pop();
            }
            else
            {
                break;
            }
        }
        ans = max(ans, (ll)(q.size() + 1));
        q.push(vecz[i].second);
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}