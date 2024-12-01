#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b; cin >> a >> b;
    int cnt = 0;
    while(a<=b)
    {
        a *= 3; b *= 2;
        cnt++;
    }
    cout << cnt;
    return 0;
}
