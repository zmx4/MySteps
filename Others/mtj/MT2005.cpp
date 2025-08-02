#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
int tar,n;

ll qpow(ll a,ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);


    int A,B;
    cin >> A >> B >> n;
    tar = B - A;
    for(int i = -2000;i <= 2000;i++)
    {
        if(pow(i, n) == tar)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << "No solution" << endl;

    return 0;
}