#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
const int M = 5 * N;
int trie[N*4][26];
int cnt[M], ed[M];
int pos = 1;
int n, k;
void insert(string str)
{
    int t = 1;
    cnt[t]++;
    for (auto x : str)
    {
        int c = x - 'a';
        int &v = trie[t][c];
        if (!v)
            v = ++pos;
        t = v;
        cnt[t]++;
    }
    ed[t]++;
}
string ans = "";
bool flag = false;
void dfs(int now)
{
    if (flag)
        return;
    int t = ed[now];
    for (int i = 0; i <= 25; ++i)
    {
        if (trie[now][i])
            t++;
    }
    if (t >= k)
    {
        flag = true;
        return;
    }
    for (int i = 0; i <= 25; ++i)
    {
        int x = trie[now][i];
        if (!cnt[x])
            continue;
        t = t - 1 + cnt[x];
        if (t >= k)
        {
            k -= t - cnt[x];
            ans += 'a' + i;
            dfs(x);
            break;
        }
    }
}
void solve()
{
    cin >> n >> k;
    flag = false;
    ans = "";
    for (int i = 1; i <= pos; ++i)
    {
        cnt[i] = ed[i] = 0;
        memset(trie[i], 0, sizeof trie[i]);
    }
    pos = 1;
    for (int i = 1; i <= n; ++i)
    {
        string str;
        cin >> str;
        insert(str);
    }
    dfs(1);
    if (!ans.empty())
        cout << ans << endl;
    else
        cout << "EMPTY" << endl;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}