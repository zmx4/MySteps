#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n, t;
    cin>>n>>t;
    string s;
    if(t == 10)
    {
        if(n == 1)
        {
            cout<<-1<<endl;
            return 0;
        }
        for(int i=0; i<n-1; i++)
            s += '1';
        s += '0';
        cout<<s<<endl;
    }
    else
    {
        for(int i=0; i<n; i++)
            s += to_string(t);
        cout<<s<<endl;
    }

	return 0;
}