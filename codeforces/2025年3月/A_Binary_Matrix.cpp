#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    for(int i = 0;i < n;i++)
    {
        string s;
        cin>>s;
        for(int j = 0;j < m;j++)
        {
            a[i][j] = s[j]-'0';
        }
    }
    int row = 0,col = 0;
    for(int i = 0;i < n;i++)
    {
        bool flag = false;
        for(int j = 0;j < m;j++)
        {
            flag ^=a[i][j];
        }
        if(flag)
        {
            row++;
        }
    }
    for(int j = 0;j < m;j++)
    {
        bool flag = false;
        for(int i = 0;i < n;i++)
        {
            flag ^=a[i][j];
        }
        if(flag)
        {
            col++;
        }
    }
    cout<<max(row,col)<<endl;
    
    
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}