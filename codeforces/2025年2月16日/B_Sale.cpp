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
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int sum=0;
    for(int i=0;i<m;i++)
    {
        if(a[i]>=0)
        {
            break;
        }
        sum+=a[i];
    }
    cout<<-sum<<endl;

	return 0;
}