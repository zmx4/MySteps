#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int calc(int n)
{
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve()
{
    int x,y;
    cin>>x>>y;
    if((x+1-y)%9==0&&(x+1-y)>=0)
    {
        cout<<"Yes"<<endl;
        return;
    }
    else
    {
        cout<<"No"<<endl;
    }
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