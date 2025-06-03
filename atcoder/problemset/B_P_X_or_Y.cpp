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
    int x,y;
    cin >> x >> y;
    int ans1 = 0, ans2 = 0;
    for(int i = 1;i <= 6;i++)
    {
        for(int j = 1;j <= 6;j++)
        {
            if(abs(i-j)>=y||i + j >= x)ans2++;
        }
    }
    
    cout << setprecision(10) << (ans1+ans2) / 36. << endl;
    
    
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr),cout.tie(nullptr);
    //char readBuffer[1 << 20];
    //cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T = 1;//cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}