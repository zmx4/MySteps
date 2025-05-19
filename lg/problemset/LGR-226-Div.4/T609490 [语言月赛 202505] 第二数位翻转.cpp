#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
string remove(string &str)
{
    string ans;
    int i;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] != '0')
        {
            break;
        }
    }
    for (; i < str.size(); i++)
        {
            ans += str[i];
        }
    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    string str;
    cin >> str;
    if(str.size() % 2 == 1)
    {
        str = "0" + str;
    }
    //cout<<str<<endl;
    vector<string> p;
    for(int i = 0;i < str.size();i+=2)
    {
        p.push_back(str.substr(i,2));
    }
    //for(auto i:p)cout<<i<<endl;
    for(int i = 0;i < p.size() / 2;i++)
    {
        swap(p[i],p[p.size() - 1 - i]);
    }
    string ans = "";
    for(int i = 0;i < p.size();i++)
    {
        ans += p[i];
    }
    //cout<<ans<<endl;
    string ans1 = remove(ans);
    cout<<ans1<<endl;
    return 0;
}