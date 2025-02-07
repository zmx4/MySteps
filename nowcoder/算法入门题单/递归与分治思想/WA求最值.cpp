#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 1e6 + 10;
int a[N];

inline int g(int i ,int j)
{
	register int sum = 0;
	for(register int k = min(i,j);k <= max(i,j);k++)
		sum += sum + a[k];
	return sum;
}

inline int f(int i,int j)
{
	return (i-j)*(i-j) + g(i,j)*g(i,j);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int ans = INT_MAX;
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			ans = min(ans,f(i,j));
	cout << ans << endl;
		return 0;
}