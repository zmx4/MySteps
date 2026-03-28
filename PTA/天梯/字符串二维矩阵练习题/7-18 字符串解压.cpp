#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
vector<pair<char, int>> v;


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int index = 0;
    int cnt = 0;
    int num = 0;
    string res;
    for (char c : s)
    {
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        else
        {
            if (num == 0)
                num = 1;           
            res += string(num, c); 
            num = 0;               
        }
    }
    cout << res << endl;
    return 0;
}