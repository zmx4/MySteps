#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    string s;
    cin>>s;
    vector<int> v(s.size(),0);
    for(int i=1; i<s.size(); i++)
    {
        if(s[i] == s[i-1])
            v[i] = v[i-1]+1;
        else
            v[i] = v[i-1];
    }
    int T;
    cin>>T;
    while(T--)
    {
        int l,r;
        cin>>l>>r;
        cout<<v[r-1]-v[l-1]<<endl;
    }

	return 0;
}