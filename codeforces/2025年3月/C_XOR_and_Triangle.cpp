#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
#pragma region C_XOR
void solve()
{
    int n;
    cin>>n;
    bitset<64> a(n);
    int cnt = 0,temp = n;
    while(temp)
    {
        cnt++;
        temp/=2;
    }
    if(a.count()<=1||a.count()==cnt)
    {
        cout<<-1<<endl;
    }
    else
    {
        bitset<64> b;
        bool flag = false;
        int pos1 = -1,pos0=-1;
        for(int i = 63;i >= 0;i--)
        {
            if(a[i])b[i]=1;
            if(a[i]&&!flag)
            {
                flag = true;
                pos1 = i;
            }
            else if(!a[i]&&flag&&pos1!=-1)
            {
                pos0 = i;
            }
            
        }
        b[pos1]=0;
        b[pos0]=1;
        cout<<b.to_ullong()<<endl;
    }
}
#pragma endregion
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
