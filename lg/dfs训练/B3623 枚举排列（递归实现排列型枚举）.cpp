#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int path[N];
bool st[N];

int n,k;

void dfs(int u)
{
    if(u==k)
    {
        for(int i = 0;i < u;i++)cout<<path[i]<<" ";
        cout<<endl;
        return;
    }

    for(int i = 1;i <= n;i++)
    {
        if(!st[i])
        {
            path[u]=i;
            st[i]=true;
            dfs(u+1);
            st[i]=false;
        }
    }
}



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n>>k;

    dfs(0);

    return 0;
}