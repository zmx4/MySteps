#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
void tolower(string &s)
{
    for(auto &x : s) x = tolower(x);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n;
    cin >> n;
    string str;
    cin.ignore();
    getline(cin, str);
    string str2 = str;
    tolower(str2);
    vector<string> s(n);
    for(auto &x : s)
    {
        getline(cin, x);
        tolower(x);
    }
    for(auto x:s)
    {
        while(str2.find(x) != string::npos)
        {
            int pos = str2.find(x);
            str.replace(pos, x.size(), string(x.size(), '*'));
            str2.replace(pos, x.size(), string(x.size(), '*'));
        }
    }
    cout << str << endl;

    return 0;
}