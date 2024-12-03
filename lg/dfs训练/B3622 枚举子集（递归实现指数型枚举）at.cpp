#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
bool arr[20];

void printa()
{
    for (int i = 1; i <= n; i++)
    {
        cout << (arr[i] ? "Y" : "N");
    }
    cout << endl;
}

bool judge()
{
    for (int i = 1; i <= n; i++)if (!arr[i])return false;
    return true;
}

void solve(int pos)
{
    if (pos > n)
    { 
        printa();
        if (judge())return;
        
        return;
    }

    arr[pos] = false;
    solve(pos + 1);

    arr[pos] = true;
    solve(pos + 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    solve(1);

    return 0;
}