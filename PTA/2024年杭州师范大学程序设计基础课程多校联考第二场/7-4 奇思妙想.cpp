#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    int a,b,n;cin>>a>>b>>n;
    int cnt = 0;
    while(!(a>n)&&!(b>n))
    {
        cnt++;
        if(a+2*b>b+2*a)
        {
            a=a+b;
            cout<<"a"<<" "<<a<<endl;
        }
        else 
        {
            b=b+a;
            cout<<"b"<<" "<<b<<endl;
        }
    }
    cout<<cnt;
}