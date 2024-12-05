#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2010;
int n,m;
int u,v;
int path[N][N];bool st[N];
int cnt[N];
int sum = 0;

void dfs(int r)
{
    if(r == v)
    {
        sum++;
        for(int i = 1;i <= n;i++)
        {
            if(st[i]==true)
            {
                cnt[i]++;
            }
        }
		
    }
    for(int i = 1;i <= n;i++)
    {
        if(path[r][i]==1 && st[i]==false)
        {
            st[i]=true;
            dfs(i);
            st[i]=false;
        }
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
        path[v][u]=1;
    }

    cin>>u>>v;
    dfs(u);
    int res = 0;
    for(int i = 1;i <= n;i++)
    {
        if(cnt[i]==sum)
        {
            res++;
        }
    }
    if(sum==0)cout<<"-1";
    else
    {
        cout<<res - 1;
    }
    return 0;
}