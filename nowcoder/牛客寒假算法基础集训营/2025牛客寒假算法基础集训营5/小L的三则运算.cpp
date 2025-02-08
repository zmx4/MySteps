#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    ll x;char op;
    cin>>x>>op;
    if(op=='*')
    {
        cout<<"1 " <<x<<endl;
    }
    else if(op == '+')
    {
        cout<<"1 "<<x-1<<endl;
    }
    else if(op == '-')
    {
        cout<<x+1<<" 1"<<endl;
    }

	return 0;
}