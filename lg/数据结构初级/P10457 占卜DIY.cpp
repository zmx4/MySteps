#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	deque<int> q[14];
	int cnt[14]={0};
	for(int i=1;i<=13;i++)
	{
		for(int j=1;j<=4;j++)
		{
			char c;
			cin>>c;
			if(c=='0')q[i].push_back(10);
			else if(c=='J')q[i].push_back(11);
			else if(c=='Q')q[i].push_back(12);
			else if(c=='K')q[i].push_back(13);
			else if(c=='A')q[i].push_back(1);
			else
				q[i].push_back(c - '0');
		}
	}
	while (!q[13].empty())
	{
		int x = q[13].front();
		q[13].pop_front();
		while(x!=13)
		{
			cnt[x]++;
			int temp = q[x].back();
			q[x].pop_back();
			x = temp;
		}
	}
	int ans = 0;
	for(int i=1;i<=13;i++)
	{
		if(cnt[i]==4)ans++;
	}
	cout<<ans<<endl;
	return 0;
}