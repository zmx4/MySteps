#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ll n;
    cin>>n;
    if(n>0)cout<<n<<endl;
    else
    {
        string s=to_string(n);
        if(s[s.size()-1]>s[s.size()-2])s.erase(s.size()-1,1);
        else s.erase(s.size()-2,1);
        int ans=stoi(s);
        cout<<ans<<endl;
    }

    return 0;
}