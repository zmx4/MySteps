#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    map<int, int> mp;
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == 4 || x == 6)
            continue;
        if (y == 0)
        {
            cnt0++;
        }
        else
        {
            cnt1++;
        }
        mp[x]++;
    }
    if (cnt0 > cnt1)
    {
        cout << "0 " << cnt0 << endl;
    }
    else if (cnt0 < cnt1)
    {
        cout << "1 " << cnt1 << endl;
    }
    else
    {
        cout << "LOVE " << cnt0 << endl;
    }
    int maxx = -1;
    for (auto [x, y] : mp)
    {
        maxx = max(maxx, y);
    }
    if (maxx != -1)
        cout << maxx;
    vector<int> ans;
    for (auto [x, y] : mp)
    {
        if (y == maxx)
        {
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << " " << x;
    }

    return 0;
}