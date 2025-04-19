#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using namespace std;
signed main()
{
	
	int n;cin>>n;
	bitset<64>bit(n);
	bool flag = false;
	for(int i = 63;i >= 0;i--)
	{
		if(flag && bit[i])bit[i]=0;
		if(bit[i])flag = true;
	}
	int index = 0;
	for(int i = 63;i >= 0;i--)
	{
		if(bit[i])
		{
			index = i;break;
		}
	}
	int x = 1;
	while(index--)x*=2;
	cout<<x<<endl;
}