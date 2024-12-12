#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n, k, l, c, d, p, nl, np;
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;

	int totalDrink = k*l/nl;
	int limestone = c*d;
	int salt = p/np;

	int ans = std::min(totalDrink, std::min(limestone, salt))/n;

	cout<<ans<<endl;

		return 0;
}