//24-11-25 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    if (a[2]!=1)
    {
        sort(a, a+3);
        if(a[2]==1)cout << "3";
        else if(a[1]==1)cout << 2*a[2];
        else if(a[0]==1)cout << (1+a[1])*a[2];
        else cout << a[1]*a[0]*a[2];
    }
    else
    {
        sort(a, a+2);
        if(a[1]==1)cout << "3";
        else if(a[0]==1)cout << a[1]+a[0]+a[2];
        else cout << a[0]*(a[1]+a[2]);
    }
    return 0;
}
