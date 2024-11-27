#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a; cin >> a;
    int sign = 0, sign7 = 0, sign4 = 0, signis = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != '4' && a[i] != '7')
        {
            sign++;
            //break;
        }
        else if (a[i] == '4' || a[i] == '7')
        {
            signis++;
        }
        if (a[i] == '7')sign7 = 1;
        if (a[i] == '4')sign4 = 1;
    }
    
    //cout << signis;
    if ((signis == 4 || signis == 7) && signis != 0)cout << "YES";
    else cout << "NO";

    return 0;
}
