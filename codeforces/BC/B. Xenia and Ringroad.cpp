#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n,m;cin>>n>>m;
	vector<int> tasks(m);
	for(int i=0;i<m;i++) cin>>tasks[i];
	
	long long ans=0;
	int cur=1;

	for (int i = 0; i < m;i++)
	{
		int target = tasks[i];
		if(target>=cur)
		{
			ans += target - cur;
		}
		else
		{
			ans += n - cur + target;
		}
		cur = target;
	}
	cout<<ans<<endl;
		return 0;
}