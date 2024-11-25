//24-11-24 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;cin>>s;
    bool flag = false;
    if(s.find("H") != string::npos)flag = true;
    if(s.find("Q") != string::npos)flag = true;
    if(s.find("9") != string::npos)flag = true;
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
