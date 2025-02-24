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
    if(n%2==0)
    {
        cout<<n/2<<endl;
        for(int i=0;i<n/2;i++)
        {
            cout<<2<<" ";
        }
    }
    else
    {
        cout<<n/2<<endl;
        for(int i=0;i<n/2-1;i++)
        {
            cout<<2<<" ";
        }
        cout<<3;
    }

	return 0;
}