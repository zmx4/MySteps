#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6+10;
int ne[N];
vector<int> ans;
inline void getne(const string &s)
{
    int n = s.size();
    ne[0] = -1;
    for (int i = 1;i < n; i++)
    {
        int j = ne[i - 1];
        while (j >= 0 && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j++;
        ne[i] = j;
    }
}
// void kmp(const string &s1, const string &s2)
// {
//     // cout << s1 << ' ' << s2 << endl;
//     int n = s1.size(), m = s2.size();
//     int i = 0, j = 0;
//     while(j < n)
//     {
//         if(s2[i]==s1[j])
//         {
//             ++i, ++j;
//             if(i == m)
//             {
//                 // cout << j - m + 1 << endl; // 输出匹配位置
//                 ans.push_back(j - m + 1); // 存储匹配位置
//                 i = ne[i - 1] + 1; // 回溯到最长前缀后缀
//             }
//         }
//         else
//         {
//             if(i == 0)
//             {
//                 ++j; // 如果i为0，直接移动j
//             }
//             else
//             {
//                 i = ne[i - 1] + 1; // 否则回溯到最长前缀后缀
//             }
//         }
//     }
// }
void kmp(const string &p, const string &t)
{
    int m = p.size(), n = t.size();
    int i = 0, j = 0;
    while (j < n)
    {
        if (i < m && p[i] == t[j])
        {
            i++;
            j++;
            if (i == m)
            {
                ans.push_back(j - m + 1);
                i = ne[i - 1] + 1;
            }
        }
        else
        {
            if (i == 0)
            {
                j++;
            }
            else
            {
                i = ne[i - 1] + 1;
            }
        }
    }
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    // cout<<s1<<' '<<s2<<endl;
    getne(s2);
    kmp(s2, s1);
    for(auto &x : ans)
    {
        cout << x << endl; // 输出匹配位置
    }
    for(int i = 0; i < s2.size(); i++)
    {
        cout << ne[i] + 1 << ' '; // 输出ne数组
    }
    
    
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}