#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int mina = INT_MAX,minb = INT_MAX;
	int maxa = 0,maxb = 0;
	int n;cin >> n;
	for(int i = 0;i < n;++i)
	{
		int x,y;cin >> x >> y;
		mina = min(mina,x);
		minb = min(minb,y);
		maxa = max(maxa,x);
		maxb = max(maxb,y);
	}
	cout << (maxa - mina) * (maxb - minb);
	
	
	
	return 0;
}
