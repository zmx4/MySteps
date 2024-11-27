#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a; cin >> a;
    int b[200] = { 0 }; int d = 0;
    for(int i = 0;i < a.length();i++)
    {
        if (b[a[i]] == 0)
        {
            b[a[i]]++;
            d++;
        }
    }
    if (d % 2 == 0)cout << "CHAT WITH HER!";
    else cout << "IGNORE HIM!";
    return 0;
}
