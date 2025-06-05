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
    cin>>n;
    string s;
    cin>>s;

    map<char, int> mp;
    for(auto c:s)
    {
        mp[c]++;
    }

    bool ok = true;
    for(auto [c, cnt]: mp)
    {
        if(islower(c))
        {
            if(mp[c - 'a' + 'A'] == 0)
            {
                ok = false;
                break;
            }
        }
        else
        {
            if(mp[c - 'A' + 'a'] == 0)
            {
                ok = false;
                break;
            }
        }
    }
    if(ok)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }






    return 0;
}