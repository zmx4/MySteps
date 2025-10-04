#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    unsigned int n;
    while (cin >> n)
    {
        bitset<16> bs(n); // 65535最多16位
        cout << bs.count() << endl;
    }

        return 0;
}