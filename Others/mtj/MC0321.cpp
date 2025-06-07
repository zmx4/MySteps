#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll high = 1;
    while (high <= n)
        high <<= 1;
    ll low = high >> 1; // 不超过 n 的最大 2 的幂

    if (n - low <= high - n)
        cout << low << endl;
    else
        cout << high << endl;

    return 0;
}