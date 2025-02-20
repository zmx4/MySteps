#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    ll n;
    cin>>n;
    ll cnt = 0;
    ll sum = 0;
    while(sum<=n)
    {
        cnt++;
        sum+=cnt*(cnt+1)/2;
    }
    cout<<cnt-1<<endl;
	return 0;
}