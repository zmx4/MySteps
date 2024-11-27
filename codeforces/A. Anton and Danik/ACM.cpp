#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A = 0, D = 0;
    int n; cin >> n;
    string a; cin >> a;
    for (int i = 0;i < n;i++)
    {
        if (a[i] == 'A')A++;
        if (a[i] == 'D')D++;
    }
    if (A > D)cout << "Anton";
    if (A < D)cout << "Danik";
    if (A == D)cout << "Friendship";
    return 0;
}
