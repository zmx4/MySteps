#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
vector<int> a;
void solve()
{
    int x;cin>>x;
    int pos = upper_bound(a.begin(),a.end(),x)-a.begin();
    cout<<pos<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    for(int i=0;i<T;i++)
    {
        int x;cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int Q;cin>>Q;
    //Q++;
    //cout<<Q<<endl;
    while(Q--)
    {
        solve();
    }
    
    return 0;
}