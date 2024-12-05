#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int team[100];

int n;
int path[100];
bool st[100]={true};
void dfs(int u)
{
    if(n==u)
    {
        for(int i = 0;i < n;i++)
        {
            cout<<path[i]<<" ";
        }
        puts("");
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
    cin>>n;

    dfs(0);

    return 0;
}