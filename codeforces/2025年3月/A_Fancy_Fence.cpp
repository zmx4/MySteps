#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

vector<int> v;
void init()
{
    for(int i = 3; i <= 1800; i++)
    {
        if(((i-2)*180) % i == 0)
        {
            v.push_back(((i-2)*180)/i);
        }
    }
}
void solve()
{
    int n;cin>>n;
    if(find(v.begin(),v.end(),n) != v.end())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    init();
    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}