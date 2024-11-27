#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a; cin >> a;
    int sum = 0, temp = 0;
    for (int i = 1;i <= a.length();i++)
    {
        if (a[i] == a[i - 1])
        {
            temp++;
            //cout << temp << endl;
        }
        else
        {
            temp++;
            sum = max(sum, temp);
            temp = 0;
            //cout << sum << endl;
        }
        //cout << sum << " " << temp << endl;
    }
    
    sum = max(sum, temp);
    //cout << sum << endl;
    if (sum >= 7)cout << "YES";
    else cout << "NO";
    return 0;
}
