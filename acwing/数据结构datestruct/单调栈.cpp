#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 100010;
int n;
int skt[N],top;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n;
	for(int i = 0;i < n;i++)
	{
		int x;
		cin>>x;
		while(top && skt[top] >= x) top--;
		if(top)cout<<skt[top]<<" ";
		else cout<<"-1 ";
		//else cout<<"-1 "<<endl;
		skt[++top] = x;
	}

	return 0;
}