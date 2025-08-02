#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> presum(n + 1, 0);
    for (int i = 0; i < n; i++)
        presum[i + 1] = presum[i] + a[i];
    deque<int> q;
    int max_sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!q.empty() && q.front() < i - m)
            q.pop_front();

        if (!q.empty())
        {
            max_sum = max(max_sum, presum[i] - presum[q.front()]);
        }
        while (!q.empty() && presum[q.back()] >= presum[i])
            q.pop_back();

        q.push_back(i);
    }
    cout << max_sum << endl;
        return 0;
    }