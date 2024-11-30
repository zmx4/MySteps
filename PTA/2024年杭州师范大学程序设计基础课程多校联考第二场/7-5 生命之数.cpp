#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string n;
    cin >> n;
    bool flag = true;

    for (int i = 1; i < n.length() - 1; ++i)
    {
        if (n[i] == n[i - 1] || (i + 1 < n.length() && n[i] == n[i + 1]))
        {
            flag = false;
            break;
        }
        if (!((n[i - 1] > n[i] && n[i] < n[i + 1]) || (n[i - 1] < n[i] && n[i] > n[i + 1])))
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "Life";
    else
        cout << "Leave";
    return 0;
}