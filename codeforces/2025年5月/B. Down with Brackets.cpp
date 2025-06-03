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
    string str;
    cin >> str;
    int n = str.size();
    int cnt = 0;
    for(int i = 1;i < n - 1;i++)
    {
        if(str[i] == '(')
        {
            cnt++;
        }
        else if(str[i] == ')')
        {
            cnt--;
        }
        if(cnt < 0)
        {
            cout << "YES" << endl;
            return;
        }
    }
    if(cnt == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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