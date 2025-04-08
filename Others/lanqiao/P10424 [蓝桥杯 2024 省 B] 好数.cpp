#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

bool isgood(int n)
{
	int i = 1;
	while(n)
	{
		if(i%2==1 && (n%10)%2==0) return false;
		if(i%2==0 && (n%10)%2==1) return false;
		n/=10;
		i++;
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(isgood(i)) ans++;
	}
	cout << ans << endl;
	return 0;
}