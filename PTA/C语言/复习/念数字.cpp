#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int b=a.length();
    for(int i=0;i<=b;i++)
    {
        if(a[i]=='-')cout<<"fu ";
        if(a[i]=='1')cout<<"yi ";
        if(a[i]=='2')cout<<"er ";
        if(a[i]=='3')cout<<"san ";
        if(a[i]=='4')cout<<"si ";
        if(a[i]=='5')cout<<"wu ";
        if(a[i]=='6')cout<<"liu ";
        if(a[i]=='7')cout<<"qi ";
        if(a[i]=='8')cout<<"ba ";
        if(a[i]=='9')cout<<"jiu ";
    }
}