#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		vector<int> a(n+1);
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a.begin()+1, a.end(),greater<int>());
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			//cout << a[i] << " "<<i<<endl;
			if(a[i] >= i)
				cnt++;
		cout << cnt << endl;
	}

	return 0;
}