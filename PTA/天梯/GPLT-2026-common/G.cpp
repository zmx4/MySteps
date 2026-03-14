#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isnum(int x)
{
	int w = 1;
	while(w * w < x)
	{
		w ++;
	}
	return w * w == x;
}
bool isnumm(int x)
{
	int w = 1;
	while(w * w * w < x)
	{
		w ++;
	}
	return w * w * w== x;
}
void solve()
{
	int x;
	cin >> x;
	int d = x / 2;
	int t = x / 3;
	if(isnum(d) && isnumm(t))
	{
		cout << x <<" is a triple flower";
	}
	else if(isnum(d))
	{
		cout << x <<" is a double flower";
	}
	else
	{
		cout << x <<" is "<<x;
	}
	cout << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
}
