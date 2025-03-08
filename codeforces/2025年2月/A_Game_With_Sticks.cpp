#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    if(min(n,m)%2==0)
        cout<<"Malvika"<<endl;
    else
        cout<<"Akshat"<<endl;

	return 0;
}