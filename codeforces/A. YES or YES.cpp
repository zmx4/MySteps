#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;cin>>n;
	while(n--)
	{
		string a;
		cin >> a;
		a[0] = tolower(a[0]);
		a[1] = tolower(a[1]);
		a[2] = tolower(a[2]);
		if(a == "yes")
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}