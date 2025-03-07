#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    char s[10][10];
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            cin >> s[i][j];

    int ans = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(s[i][j]=='X'){
                int ring = min({i, j, 9-i, 9-j});
                ans += (ring + 1);
            }
        }
    }
    cout << ans << endl;
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