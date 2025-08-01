#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        s[i] = s[i - 1] + val;
    }

    deque<int> q;  
    q.push_back(0);

    int max_sum = -2e18;

    for (int i = 1; i <= n; i++)
    {
        if (!q.empty() && q.front() < i - m)
            q.pop_front();

        if (!q.empty())
        {
            max_sum = max(max_sum, s[i] - s[q.front()]);
        }
        while (!q.empty() && s[q.back()] >= s[i])
            q.pop_back();

        q.push_back(i);
    }

    cout << max_sum << endl;

    return 0;
}