#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n;
    cin>>n;
    unordered_map<int,unordered_set<int,custom_hash>,custom_hash> mp;
    int r,c;
    cin>>r>>c;
    const int N = 2e5+10;
    vector<vector<int>> g(r,vector<int>(c));
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
        {
            cin>>g[i][j];
        }
    }
    for(int i = 0;i < r;i++)
    {
        for(int j = 0;j < c;j++)
        {
            if(i-1 >= 0)
            {
                mp[g[i][j]].insert(g[i-1][j]);
            }
            if(i+1 < r)
            {
                mp[g[i][j]].insert(g[i+1][j]);
            }
            if(j-1 >= 0)
            {
                mp[g[i][j]].insert(g[i][j-1]);
            }
            if(j+1 < c)
            {
                mp[g[i][j]].insert(g[i][j+1]);
            }
        }
    }
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(mp[x].count(y))
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }





    return 0;
}