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
    if(n%2==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++)a[i]=i;
    for(int i = 1;i <= n;i+=2)swap(a[i],a[i+1]);
    for(auto i:a)if(i!=0)cout<<i<<" ";
	return 0;
}