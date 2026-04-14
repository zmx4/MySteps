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

    int n;
    string s;
    cin >> n >> s;
    char c = 'o';
    int index = 0;
    while(index < n && s[index] == c)
    {
        index++;
    }
    s.erase(0,index);
    cout << s << endl;

    return 0;
}