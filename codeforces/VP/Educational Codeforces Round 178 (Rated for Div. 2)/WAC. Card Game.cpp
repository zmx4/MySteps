#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;
	cin >> n;
	vector<int> A, B;
	A.reserve(n);
	B.reserve(n);
	for (int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		int u = (i == 1 ? n + 1 : i);
		if (c == 'A')
			A.push_back(u);
		else
			B.push_back(u);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int winsA = 0, winsB = 0;
	while (!A.empty() && !B.empty())
	{
		if (A.back() > B.back())
		{
			winsA++;
		}
		else
		{
			winsB++;
		}
		A.pop_back();
		B.pop_back();
	}
	cout << (winsA > winsB ? "Alice\n" : "Bob\n");
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}