#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n; int steps = 0;
    if (n <= 5)cout << "1";
    else
    {
        steps = n / 5;
        if (steps * 5 != n)cout << steps + 1;
        else cout << steps;
    }
    

    return 0;
}
