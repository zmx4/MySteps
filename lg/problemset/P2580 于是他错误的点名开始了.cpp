#include <bits/stdc++.h>
#define endl "\n"
#define uint64_t unsigned long long
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

unordered_map<string, int> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]=1;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if(mp.find(s)== mp.end())
        {
            cout << "WRONG" << endl;
        }
        else if(mp[s]== 0)
        {
            cout << "REPEAT" << endl;
        }
        else
        {
            cout << "OK" << endl;
            mp[s]--;
        }
    }






    return 0;
}