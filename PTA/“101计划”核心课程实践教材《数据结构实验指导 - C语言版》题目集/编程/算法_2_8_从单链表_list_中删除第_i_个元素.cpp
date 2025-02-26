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
        l.push_front(x);
    }
    int k;
    cin >> k;
    if (k > n || k < 1)
    {
        cout << "错误：删除位置不合法。" << endl;
        cout << n << ": ";
        for (auto ita = l.begin(); ita != l.end(); ita++)
        {
            cout << *ita << (ita == --l.end() ? "\n" : " ");
        }
        return 0;
    }
    if(n==1&&k == 1)
    {
        cout << n - 1<< ":";
        return 0;
    }
    auto it = l.begin();
    for (int i = 1; i < k; i++)
    {
        it++;
    }
    l.erase(it);
    cout << n - 1 << ": ";
    for (auto ita = l.begin(); ita != l.end(); ita++)
    {
        cout << *ita << (ita == --l.end() ? "\n" : " ");
    }

    return 0;
}