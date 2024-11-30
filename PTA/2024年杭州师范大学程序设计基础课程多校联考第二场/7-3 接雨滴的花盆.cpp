#include<bits/stdc++.h>
using namespace std;

signed main()
{
    long long int n,a = 0,b = 0;cin>>n;
    int sign = 0;
    for(int i = 1;a < n;i++)
    {
        a+=(i+1)*(i+2)/2;
        sign = i;
    }
    cout<<sign;
}