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
    for(int i = 0;i<n;i++)cin>>a[i];
    set<int> s;
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--)
    {
        s.insert(a[i]);
        ans[i] = s.size();
    }
    while(m--)
    {
        int x;
        cin>>x;
        cout<<ans[x-1]<<endl;
    }

    return 0;
}