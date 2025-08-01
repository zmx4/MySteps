#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
int g[20][20];
vector<int> tar(6);
vector<int> ans;
bool vis[20];
bool flag = false;
int n;
void dfs(int u, vector<int>& tmp,vector<int>& sum)
{
    if (flag) return;
    if(sum==tar)
    {
        ans = tmp;
        flag = true;
    }
    for (int j = 1; j <= 5;j++)
    {
        if(sum[j]>tar[j])return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            tmp.push_back(i);
            vector<int> newSum(6);
            for (int j = 1; j <= 5; j++)
            {
                newSum[j] = sum[j] + g[i][j];
            }
            dfs(i, tmp, newSum);
            tmp.pop_back();
            vis[i] = false;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j =1; j <= 5; j++)
        {
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <=5; i++  )cin >> tar[i];
    vector<int> tmp;
    vector<int> sum(6);
    for(int i = 1; i <= n; i++)
    {
        vis[i] = false;
    }
    dfs(1, tmp, sum);
    for(auto x : ans)cout << x << " ";
    cout << endl;
    return 0;
}