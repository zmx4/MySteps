#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool isPrime(const ll &n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve()
{
    ll n;
    cin >> n;
    if (n % 2 != 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        while (n % 2 == 0)
        {
            n /= 2;
        }
        if (n > 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }   
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}