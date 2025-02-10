//24-11-27 Tick
//false
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool judge(const int a[],const int b[])
{

    for(int i='A';i<='Z';i++)
    {
        //cout<<a[i]<<" "<<b[i]<<endl;
        if(a[i]==0&&b[i]!=0)
        {
            //cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
            printf("%c %d %d",i,a[i],b[i]);
            return false;
        }
    }

    //if (a[0] == a[1])return false;
    return true;
}
int q[200],w[200];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //int n;cin>>n;

    string a,b,c;

    getline(cin,a);
    getline(cin,b);
    getline(cin,c);

    //cin>>a>>b>>c;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    string d = "NewYearandChristmasMen";
    for(int i = 0;i < a.length();i++)
    {
        q[a[i]]+=1;
        //cout<<a[i]<<" "<<q[a[i]]<<endl;
    }
    //cout<<q[69]<<endl;
    for(int i = 0;i < b.length();i++)
    {
        q[b[i]]++;
    }
    //cout<<q[69]<<endl;
    for(int i = 0;i < c.length();i++)
    {
        q[c[i]]++;
        //cout<<q[c[i]]<<endl;
    }
    //cout<<q[69]<<endl;
    for(int i = 0;i < d.length();i++)
    {
        d[i] = toupper(d[i]);
        w[d[i]]++;
    }
    /*
    for(int i = 0;i < 'Z';i++)
    {
        if(q[i]!=w[i])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    */

    if(judge(q,w))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
