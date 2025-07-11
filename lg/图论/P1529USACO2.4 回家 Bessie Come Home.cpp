#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
vector<vector<pair<int,int>>> g;
bool vis[512];
int dist[512];
static char space[1000000], *sp = space;
template <typename T>
struct myalloc : allocator<T>
{
    myalloc(){}
    template<typename T2>
    myalloc(const myalloc<T2> &a){}
    template<typename T2>
    myalloc<T>& operator=(const myalloc<T2> &a){return *this;}
    template<typename T2>
    struct rebind{typedef myalloc<T2> other;};
    inline T* allocate(size_t n){
        T *result=(T*)sp;sp+=n*sizeof(T);
        return result;
    }
    inline void deallocate(T* p,size_t n){}
};
void solve()
{
    int p;cin >> p;
    g.resize(256, vector<pair<int, int>>());
    for(int i = 1; i <= p; i++)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int s = 'Z';
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while(!q.empty())
    {
        auto [d, u] = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto &[v, w] : g[u])
        {
            if(vis[v]) continue;
            if(dist[v] > d + w)
            {
                dist[v] = d + w;
                q.push({dist[v], v});
            }
        }
    }
    int ans = 'A';
    for(int i = 'A'; i < 'Z'; i++)
    {
        if(dist[i] < dist[ans]) ans = i;
    }
    cout<<char(ans) << ' ' << dist[ans] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}