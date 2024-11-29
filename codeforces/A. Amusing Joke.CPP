//24-11-27 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int q[200]={0},w[200]={0};
    string a,b,c;
    getline(cin,a);
    getline(cin,b);
    getline(cin,c);
    for(int i = 0;i < a.length();i++)
    {
        q[a[i]]++;
    }
    for(int i = 0;i < b.length();i++)
    {
        q[b[i]]++;
    }
    for(int i = 0;i < c.length();i++)
    {
        w[c[i]]++;
    }
    for(int i = 0;i < 'Z';i++)
    {
        if(q[i]!=w[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
