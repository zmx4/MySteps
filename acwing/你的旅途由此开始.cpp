#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    string s1,s2;
    cin>>s1>>s2;
    ll ans1 = 1,ans2 = 1;
    for(int i = 0;i<s1.size();i++)
    {
        ans1 *= (s1[i]-'A'+1);
    }
    for(int i = 0;i<s2.size();i++)
    {
        ans2 *= (s2[i]-'A'+1);
    }
    if(ans1%47==ans2%47)
    {
        cout<<"GO"<<endl;
    }
    else
    {
        cout<<"STAY"<<endl;
    }

	return 0;
}