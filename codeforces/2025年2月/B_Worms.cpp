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
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<int>prefix(n);
    prefix[0] = a[0];
    for(int i=1;i<n;++i)
    {
        prefix[i] = prefix[i-1]+a[i];
    }
    while(m--)
    {
        int x;
        cin>>x;
        cout<<lower_bound(prefix.begin(),prefix.end(),x)-prefix.begin()+1<<endl;
    }


	return 0;
}