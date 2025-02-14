#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> mp(n + 3, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(mp[i] > 2)
        {
            mp[i+1] += mp[i] - 2;
            mp[i] = 2;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(mp[i] % 2 == 1)
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    
    return 0;
}