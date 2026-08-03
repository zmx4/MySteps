#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+7;
const int MAXN=5e5+10;
const int INF=(1LL<<31)-1;
int d[MAXN],head[MAXN],v[MAXN];
int cnt=0;
struct edge {
    int to,next,dis;
};
edge e[MAXN];
void add(int u,int v,int w) {
    cnt++;
    e[cnt].to=v;
    e[cnt].dis=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
struct node {
    int d,p;
    bool operator < (const node &x)const {
        return x.d<d;
    }
};
priority_queue<node>q;
int n,m,s;
void dijkstra() {
    d[s]=0;
    q.push(node{0,s});
    while (!q.empty()) {
        node t=q.top();
        q.pop();
        int x=t.p,distance=t.d;
        if (v[x])
            continue;
        v[x]=1;
        for (int i=head[x];i;i=e[i].next) {
            int y=e[i].to;
            if (d[y]>d[x]+e[i].dis) {
                d[y]=d[x]+e[i].dis;
                q.push(node{d[y],y});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) d[i]=INF;
    for (int i=1;i<=m;i++) {
        int u,v,w;cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        if(d[i] >= INF) cout << INF << " ";
        else cout << d[i] << " ";
    }
    return 0;
}