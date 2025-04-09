#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
bool isPrime(int n)
{
	if(n == 1)return false;
	for(int i = 2;i * i <= n;i++)
	{
		if(n % i == 0)return false;
	}
	return true;
}
void solve()
{

	int x, k;
	cin >> x >> k;
	if(k==1 && isPrime(x) && x!=1)
	{
		cout << "YES" << endl;
		return;
	}
	else if(x==1 && k ==2)
	{
		cout<<"YES" << endl;
		return;
	}
	else
	{
		cout<< "NO" << endl;
		return;
	}
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