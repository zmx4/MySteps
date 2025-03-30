#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using ll = long long;
using ull = unsigned long long;
using namespace std;
bool ispf(int x)
{
	int a = sqrt(x*(x+1)/2);
	if (a * a == x * (x + 1) / 2)
		return 1;
	else return 0;
}
bool ispf2(int x)
{
	int a = sqrt(x);
	if (a * a == x)
		return 1;
	else return 0;
}
void solve()
{
	int n;cin>>n;
	vector<int> a(n+1,0),qzh(n+1,0);
	if(ispf(n))
	{
		cout<<-1<<endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
		qzh[i] = qzh[i-1] + a[i];
	}
	for (int i = 1;i < n; i++)
	{
		if (ispf2(qzh[i]))
		{
			swap(a[i],a[i+1]);
		}
	}
	if(ispf(qzh[n]))
	{
		swap(a[n],a[n+1]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
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