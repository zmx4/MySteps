#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int n;
	cin >> n;
	vector<int> a(n),qz(n + 1);
	for (int i = 0;i < n;++i)
		cin >> a[i];
	for (int i = 1;i <= n;++i)
		qz[i] = qz[i - 1] + a[i - 1];

	int posb = -1,pose = -1,maxs = INT_MIN;
	for(int i = 0;i < n;++i)
		for (int j = i;j < n;++j)
		{
			if (qz[j + 1] - qz[i] > maxs)
			{
				maxs = qz[j + 1] - qz[i];
				posb = i,pose = j;
			}
		}
	cout << maxs << endl;
	cout << posb + 1 << " " << pose + 1 << endl;
	return 0;
}