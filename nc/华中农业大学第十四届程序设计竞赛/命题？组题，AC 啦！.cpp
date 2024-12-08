#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		int a[n];
		for(int i = 0;i < n;i++)cin>>a[i];
		int ans = 1;
		int b[11]={0};
		for(int i = 0;i < n;i++)
		{
			b[a[i]]++;
			if(b[a[i]]==2||(i!=0&&a[i]==a[i-1]))
			{
				ans++;
				for(int j = 0;j <= 10;j++)b[i]=0;
			}
		}
		cout<<ans<<" "<<n<<endl;
	}

	return 0;
}