#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;


/*
1 N
2 G
3 NN 
4 NG
5 GN
6 GG
7 NNN
8 NNG
9 NGN
10 NGG
11 GNN
*/

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll n;
	cin >> n;
	string ans="";
	while(n!=0)
	{
		if(n%2==0)
		{
			ans+='G';
			n=(n-2)/2;
		}
		else
		{
			ans+='N';
			n=(n-1)/2;
		}
	}
	reverse(ans.begin(),ans.end());
	cout << ans;
	return 0;
}