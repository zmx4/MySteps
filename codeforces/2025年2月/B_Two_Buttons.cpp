#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int n,m;

int bfs(int x)
{
    queue<int> q;
    q.push(x);
    int cnt = 0;
    while(!q.empty())
    {
        int sz = q.size();
        while(sz--)
        {
            int u = q.front();
            q.pop();
            if(u==m)
                return cnt;
            if(u<m)
            {
                q.push(u*2);
                q.push(u-1);
            }
        }
        cnt++;
    }
    return -1;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    
    cin>>n>>m;
    if(n>m)
    {
        cout<<n-m<<endl;
        return 0;
    }
    int bound = 2 * m + 1;
    vector<int> dist(bound, -1);
    queue<int> q;
    
    dist[n] = 0;
    q.push(n);
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        if(curr == m)
        {
            cout << dist[curr] << "\n";
            return 0;
        }
        // 操作：点击红色按钮，数字乘 2
        if(curr * 2 < bound && dist[curr * 2] == -1)
        {
            dist[curr * 2] = dist[curr] + 1;
            q.push(curr * 2);
        }
        // 操作：点击蓝色按钮，数字减 1
        if(curr - 1 >= 1 && dist[curr - 1] == -1)
        {
            dist[curr - 1] = dist[curr] + 1;
            q.push(curr - 1);
        }
    }
	return 0;
}