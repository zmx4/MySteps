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
    int pos, x;
    cin >> pos >> x;
    if (pos > n + 1 || pos < 1)
    {
        cout << "错误：插入位置不合法。" << endl;
        for (auto i : l)
        {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }
    if (n > 1e4)
    {
        cout << "错误：表满不能插入。" << endl;
        for (auto i : l)
        {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }
    auto it = l.begin();
    advance(it, pos - 1);
    l.insert(it, x);
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}