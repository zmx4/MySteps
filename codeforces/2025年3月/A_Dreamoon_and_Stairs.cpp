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
    if(n<m)
    {
        cout<<-1<<endl;
        return 0;
    }
    int cnt1 = n/2 + n%2;
    while(cnt1%m!=0)
    {
        cnt1++;
    }
    cout<<cnt1<<endl;

	return 0;
}