#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n,t;
    cin>>n>>t;
    vector<int> a(n);
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    int i=1;
    while(i<t)
    {
        i+=a[i];
    }
    cout<<(i==t?"YES":"NO")<<endl;

	return 0;
}