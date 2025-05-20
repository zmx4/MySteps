#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
// const int N = 1e5+10;
const int N = 2000;
bool used[N];
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int cnt = 0;
    for(auto &c:s1)c = tolower(c);
    for(auto &c:s2)c = tolower(c);
    unordered_map<char,int> mp1,mp2;
    for(int i = 0;i < s1.size();i++)
    {
        if(s1[i] == s2[i])
        {
            cnt++;
        }
        else
        {
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
    }
    int d = 0;
    for(auto [c,i]:mp1)
    {
        if(mp2[c]>0)
        {
            cnt++;
            d++;
        }
        if(d == 2)break;
    }
    if(cnt < 4)cout<<"bull pay"<<endl;
    else cout<<"how pay"<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}