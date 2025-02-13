#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n;
	cin >> n;
	if (n % 4 != 0)
	{
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	vector<int> ans;
	for (int i = 2; i <= n; i += 2)
	{
		ans.push_back(i);
	}
	for (int i = 1; ans.size() < n - 1; i += 2)
	{
		if(i!=n-1)ans.push_back(i);
	}
	int sum = 0;
	
	for(int i=0;i<ans.size()/2+1;i++){
		sum+=ans[i];
	}
	for(int i=ans.size()/2 + 1;i<ans.size();i++){
		sum-=ans[i];
	}
	ans.push_back(sum);
	for (auto i : ans)
	{
		cout << i << " ";
	}
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}

	return 0;
}