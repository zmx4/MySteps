#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 1e5 + 10;
vector<int> prime;
bool st[N];
void seive(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!st[i])
			prime.push_back(i);
		for(int j=0;prime[j]*i<=n;j++)
		{
			st[prime[j]*i]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	seive(N);
	int n;cin>>n;
	for (int i = 0; i < n;i++)
	{
		int x;cin>>x;
		if(binary_search(prime.begin(),prime.end(),x))
			cout<<x<<" ";
	}

		return 0;
}