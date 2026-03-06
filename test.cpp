#include <bits/stdc++.h>
using namespace std;
int t, n, in[200005], dp[200005];
vector<int> g[200005];
int topsort()
{
    int ans = -1;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
            q.push(i);
        dp[i] = 0;
    } // 初始化
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ans = max(ans, dp[x]); // 统计答案
        for (int i = 0; i < g[x].size(); i++)
        {
            int nxt = g[x][i];
            dp[nxt] = max(dp[nxt], dp[x] + 1); // 转移
            if (!--in[nxt])
                q.push(nxt);
        }
    }
    return ans + 3; // 第一个 +1：边数变点数，第二个 +1：变成时刻，第三个 +1：要过一个单位时间才跟上一个时刻相等
}
void solve()
{
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        g[i].push_back(x);
        in[x]++;
    }
    cout << topsort() << '\n';
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        in[i] = 0;
    } // 多测不清空，爆零两行泪
}
int main()
{
    for (cin >> t; t--; solve())
        ;
    return 0;
}
