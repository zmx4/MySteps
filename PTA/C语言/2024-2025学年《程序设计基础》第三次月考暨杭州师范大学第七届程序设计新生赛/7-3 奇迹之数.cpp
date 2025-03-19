#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int L, R;cin>>L>>R;
	//求因子数量
	vector<int> cnt(R+1,0);
	for(int i=L;i<=R;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i%j==0)
			{
				cnt[i]++;
			}
		}
	}
	//找到最大的因子数量的数
	int maxn=0;
	for(int i=L;i<=R;i++)
	{
		maxn=max(maxn,cnt[i]);
	}
	int maxNum = 0;
	for(int i=L;i<=R;i++)
	{
		if(cnt[i]==maxn)
		{
			maxNum=i;
		}
	}
	cout<<maxNum<<endl;
	return 0;
}