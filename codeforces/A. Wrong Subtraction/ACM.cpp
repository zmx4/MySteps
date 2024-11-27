#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, n; cin >> a >> n;
    while(n--)
    {
        if (a % 10 == 0)a /= 10;
        else a -= 1;
    }
    cout << a;
    return 0;
}
