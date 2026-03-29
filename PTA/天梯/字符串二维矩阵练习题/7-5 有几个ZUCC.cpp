#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
#define int long long
ll C(int n, int m)
{
    if(m > n) return 0;
    if(m == 0 || m == n) return 1;
    ll res = 1;
    for(int i = 1; i <= m; i++)
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);


    string str;
    cin >> str;
    int z = 0,zu = 0,zuc = 0, zucc = 0;
    for(auto x : str)
    {
        if(x == 'Z') z++;
        else if(x == 'U') zu+=z;
        else if(x == 'C') 
        {
            zucc += zuc;
            zuc += zu;
        };
    }
    cout << zucc << endl;

        return 0;
}