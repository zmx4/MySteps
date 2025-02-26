#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    list<int> l;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
    int k;
    cin >> k;
    if (k > n||k<1)
    {
        cout << "错误：不存在这个元素。" << endl;
        for (auto i : l)
        {
            cout << i << " ";
        }
        return 0;
    }
    auto it = l.begin();
    for (int i = 0; i < k - 1; i++)
    {
        it++;
    }
    l.erase(it);
    for (auto i : l)
    {
        cout << i << " ";
    }

    return 0;
}