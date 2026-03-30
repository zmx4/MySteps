#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
void toLower(string &str)
{
    for (auto &x : str)
    {
        if (x >= 'A' && x <= 'Z')
        {
            x = x - 'A' + 'a';
        }
    }
}
constexpr string match = "chatgpt";
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    map<string, int> mp;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        // cin.ignore();
        string username;
        string str;
        cin >> username;
        cin.ignore();
        getline(cin, str);
        toLower(str);
        if (str.size() < match.size())
            continue;
        for (int j = 0; j < str.size() - match.size() + 1; j++)
        {
            if (str.substr(j, match.size()) == match)
            {
                mp[username]++;
            }
        }
    }
    auto cmp = [](const pair<int, string> &a, const pair<int, string> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq;
    for (auto &x : mp)
    {
        pq.push({x.second, x.first});
    }
    for (int i = 0; i < 3 && !pq.empty(); i++)
    {
        auto [count, word] = pq.top();
        pq.pop();
        cout << word << " " << count << endl;
    }

    return 0;
}