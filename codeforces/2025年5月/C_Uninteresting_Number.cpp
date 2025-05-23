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
    string num;
    cin>>num;
    int sum = 0;
    int cnt2 = 0,cnt3 = 0;
    for(auto c:num)
    {
        if(c == '2') cnt2++;
        if(c == '3') cnt3++;
        sum += c - '0';
    }
    if(sum % 9 == 0)
    {
        cout<<"YES"<<endl;
        return;
    }
    cnt2 = min(cnt2+1, 15);
    cnt3 = min(cnt3+1, 15);
    for(int i = 0; i < cnt2; i++)
    {
        for(int j = 0; j < cnt3; j++)
        {
            if((sum + 2 * i + 6 * j) % 9 == 0)
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
    
    
    
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