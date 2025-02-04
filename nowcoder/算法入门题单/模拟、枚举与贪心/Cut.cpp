#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int &i:a)
		cin >> i;
	sort(a.begin(),a.end(),greater<int>());
	vector<ll> sum(n+1);
	sum[0] = 0;
	for (int i = 1; i <= n;i++)
	{
		sum[i] = sum[i - 1] + a[i - 1];
	}
	unsigned ll Sum = 0;
	for (int i = 2; i <=n;i++)
	{
		Sum += sum[i];
	}
	cout << Sum << endl;
	return 0;
}