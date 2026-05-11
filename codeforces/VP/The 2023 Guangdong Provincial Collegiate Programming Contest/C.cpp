#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for ( int i = a; i <= b; i ++ )
#define ll long long
#define int long long
void solve()
{
    
}

signed main()
{
    ios::sync_with_stdio( false );
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        
        ll n, sum = 0, cost = 0, profit = 0;
        cin >> n;
        vector<pair<int, int>> a(n + 10);
        forr( i, 1, n ){
            cin >> a[i].first >> a[i].second;
            sum += a[i].second;
        }
        sort(a.begin() + 1, a.begin() + n + 1);
        ll cnt = 0, i0;
        forr( i, 1, n ){
            cnt += a[i].second;
            if( cnt > sum / 2 ){
                //cout << "i = " << i << endl;
                int left = sum - cnt;
                //cout << "left = " << left << endl;
                cnt -= a[i].second;
                if( cnt > left ){
                    profit += (cnt - left) * a[i].first;
                }
                else
                    cost += (left - cnt) * a[i].first;
                i0 = i + 1;
                //cout << "profit = " << profit << endl;
                break;
            }
            cost += a[i].first * a[i].second;
        }
        forr( i, i0, n ){
            profit += a[i].first * a[i].second;
        }
        cout << profit - cost << endl;
        
    }
    return 0;
}