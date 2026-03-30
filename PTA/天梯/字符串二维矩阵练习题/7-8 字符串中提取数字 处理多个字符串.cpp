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
    for(int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' && isdigit(str[i + 1]))
        {
            int num = 0;
            for (int j = i + 1; j < str.size() && isdigit(str[j]); j++)
            {
                num = num * 10 + (str[j] - '0');
            }
            if(num!=0)
            {
                cout << num << endl;
                return;
            }
        }
    }
    cout << "not find" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}