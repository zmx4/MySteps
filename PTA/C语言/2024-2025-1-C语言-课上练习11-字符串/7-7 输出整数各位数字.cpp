#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    string a;cin>>a;

    for(int i = 0;i <= a.size();i++)
    {
        cout<<a[i]<<" "[i==a.size()-1];
    }

    return 0;
}