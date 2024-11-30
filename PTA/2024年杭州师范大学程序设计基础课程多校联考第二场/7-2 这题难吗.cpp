#include<bits/stdc++.h>
using namespace std;

signed main()
{
    double a,b;cin>>a>>b;
    if(a/b>=10)cout<<"Au";
    else if(a/b>=30)cout<<"Ag";
    else if(a/b>=60)cout<<"Cu";
    else cout<<"Sign Up";
}