#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    string a,b;
    getline(cin,a);
    getline(cin,b);
    if(a>b)
    {
        cout<<1<<endl;
    }
    else if(a<b)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }

	return 0;
}