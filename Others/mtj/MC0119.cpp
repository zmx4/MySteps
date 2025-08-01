#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
int dx[] = {1,-1,1,-1,2,-2,2,-2},dy[] = {2,2,-2,-2,1,-1,-1,1};
bool vis[500][500];
int dis[500][500];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n,a,b;
    cin >> n;
    
    queue<pair<int,int>> q;
    cin >> a >> b;
    vis[a][b] = true;
    q.push({a, b});
    dis[a][b] = 0;
    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx > n || ny < 0 || ny > n || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            q.push({nx,ny});
            dis[nx][ny] = dis[x][y] + 1;
        }
    }
    int m;
    cin >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        if(vis[x][y]) cout << dis[x][y] << endl;
        else cout << -1 << endl;
    }






    return 0;
}