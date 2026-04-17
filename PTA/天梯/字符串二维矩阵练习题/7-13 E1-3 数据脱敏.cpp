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

    string s;
    char c,r;
    getline(cin, s);
    cin >> c >> r;
    for(auto &ch : s)
    {
        if(ch == c)
            ch = r;
    }
    cout << s << endl;

    return 0;
}