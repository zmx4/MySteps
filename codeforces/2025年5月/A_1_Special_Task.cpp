#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

void solve()
{
    string str;
    cin >> str;
    vector<bool> st(26, false);
    for (int i = 0; i < str.size(); i++)
    {
        if (isupper(str[i]))
        {
            st[str[i] - 'A'] = true;
        }
    }
    int ans = 1, cnt = 10;
    bool flag = false;
    for (int i = 0; i < 26; i++)
    {
        if (st[i])
        {
            if (cnt == 10 && str[0] >= 'A' && str[0] <= 'J')
                ans *= 9;
            else
                ans *= cnt;
            cnt--;
        }
    }
    if (str[0] == '?')
        {ans *= 9;}
    cout << ans;
    for (int i = 1;i < str.size();i++)
    {
        if (str[i] == '?')
        {
            cout << 0;
        }
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}