#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 1;i <=3;i++)
    {
        int x;cin>>x;
        pq.push(x);
    }
    int cnt = 5;
    
    while(cnt--)
    {
        int a = pq.top();
        pq.pop();
        a++;
        pq.push(a);
    }
    int ans = pq.top();
    pq.pop();
    for(int i = 1;i<3;i++)
    {
        ans *= pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
    return;
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