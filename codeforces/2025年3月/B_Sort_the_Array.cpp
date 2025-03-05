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
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> sorted_v = v;
    sort(sorted_v.begin(),sorted_v.end());
    int l = 0,r = n-1;
    while(l<n && v[l]==sorted_v[l])
    {
        l++;
    }
    while(r>=0 && v[r]==sorted_v[r])
    {
        r--;
    }
    if(l>r)
    {
        cout<<"yes\n";
        cout<<1<<" "<<1<<endl;
    }
    else
    {
        reverse(v.begin()+l,v.begin()+r+1);
        if(v==sorted_v)
        {
            cout<<"yes\n";
            cout<<l+1<<" "<<r+1<<endl;
        }
        else
        {
            cout<<"no\n";
        }
    }

	return 0;
}