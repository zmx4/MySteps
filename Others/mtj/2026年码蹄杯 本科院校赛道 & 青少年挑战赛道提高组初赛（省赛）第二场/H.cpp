#include<bits/stdc++.h>
using namespace std;

int getres(int n)
{
	bitset<8> bs(n);
	bitset<4> h,l;
	for(int i = 0;i < 4;++i)
	{
		h[i] = bs[i];
	}
	for(int i = 4;i < 8;++i)
	{
		l[i - 4] = bs[i];
	}
	int ans = h.to_ulong()<<4;
	ans += l.to_ulong();
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n;cin >> n;
	long long ans = 0;
	for(int i = 0;i < n;++i )
	{
		int x;cin >> x;
		ans += getres(x);
	}
	cout << ans << endl;
	
	
	return 0;
}
