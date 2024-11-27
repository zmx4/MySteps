#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a; cin >> a;
    if (a[0] >= 'a' && a[0] <= 'z')a[0] -= 32;
    cout << a;
    return 0;
}
