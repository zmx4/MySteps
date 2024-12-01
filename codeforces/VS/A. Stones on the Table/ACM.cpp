#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    string a; cin >> a;
    int cnt = 0;
    for(int i = 1;i < n;i++)
    {
        if (a[i] == a[i - 1])cnt++;
    }
    cout << cnt;
    return 0;
}
