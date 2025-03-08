#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
    
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<1<<endl;
    }
    else if(n%4==1)
    {
        cout<<8<<endl;
    }
    else if(n%4==2)
    {
        cout<<4<<endl;
    }
    else if(n%4==3)
    {
        cout<<2<<endl;
    }
    else if(n%4==0)
    {
        cout<<6<<endl;
    }
	return 0;
}