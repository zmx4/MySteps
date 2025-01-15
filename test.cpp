#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int a[1000];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int tt = -1;
	
	for (int i = 0; i < 10;i++)
	{
		a[++tt] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << a[i];
	}
}