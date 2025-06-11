#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

void solve()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ahp=min(a,c),
        bhp=min(b,d);
    // ahp--;
    if(ahp<bhp)
    {
        cout<<"Flower"<<endl;
    }
    else
    {
        cout<<"Gellyfish"<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    // char readBuffer[1 << 20];
    // cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T = 1;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}