#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using namespace std;
signed main()
{
	int a;cin>>a;
	int k = 1;
	int sum = 0;
	int ans = 0,ans2 = 0;
	for(int i = 1;i < 32;i++)
	{
		for(int j = 1;j < a;j++)
		{
			int tmp = 1;
			for(int k = 1;k <= i;k++)tmp*=j;
			sum+=tmp;
			if(sum>a)
			{
				sum = 0;
				break;
			}
			if(sum==a)ans=i,ans2 = j;
		}
	}
	for(int i = 1;i <= ans2;i++)
	{
		cout<<i<<"^"<<ans;
		if(i!=ans2)cout<<"+";
	}
	if(ans == 0)
	{
		cout<<"Impossible for "<<a<<"."<<endl;
	}
}