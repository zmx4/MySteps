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


    int x, y;
    cin >> x >> y;
    int tar1 = 100 * y / 2;
    int tar2 = (100 - x) * 100 / 2;
    cout << 5000 - tar1 - tar2 << endl;

    return 0;
}