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

    int w ,f ,a ,r;
    cin >> w >> f >> a >> r;
    bool ok = true;
    if(10 * f > 2 * w)ok = false;
    if(a * 10 > 3 * w)ok = false;
    if(w < r)ok = false;
    if(ok)cout << "Accepted" << endl;
    else cout << "Rejected" << endl;








    return 0;
}