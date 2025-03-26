#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    
    int teams = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        cnt++;
        if ((ll)cnt * a[i] >= x){
            teams++;
            cnt = 0;
        }
    }
    cout << teams << endl;
    
    
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