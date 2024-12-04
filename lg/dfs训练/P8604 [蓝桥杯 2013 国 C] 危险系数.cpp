#include <bits/stdc++.h>
using namespace std;


const int N = 2010;
int sum = 0;
int n,m;int u,v;
int path[N][N];
bool st[N][N];

void dfs(int u)
{
    if(u==v)
    {
        sum++;

        return;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        path[u][v]=1;
        path[v][u]=1;//双向联通
    }
    cin>>u>>v;

    dfs(u);

    return 0;
}