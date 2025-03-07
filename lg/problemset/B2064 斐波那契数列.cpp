#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
long long fibonacci(long long n)
{
	double phi = (1 + std::sqrt(5)) / 2; // 黄金比例
	return static_cast<long long>((std::pow(phi, n) - std::pow(1 - phi, n)) / std::sqrt(5));
}
void solve()
{
	int n;cin>>n;
	cout<<fibonacci(n)<<endl;
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