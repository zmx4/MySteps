#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int T;cin>>T;
	while(T--)
	{
		int a, b, k;cin>>a>>b>>k;
		if(a ==0||b==0)
		{
			if(k==1)
			{
				if(a==0)cout<<"1"<<endl;
				else cout<<"0"<<endl;
			}
			else cout<<"-1"<<endl;
		}
		else if (a + b - 1 < k || k < abs(a - b))
			cout << "-1" << endl;
		else
		{
			string ans = "";
			while (a > 0 && b > 0&&k>1)
			{
				ans += "01";
				a--;
				b--;
				k--;
			}
			if(a>0&&b>0){
				while (a > 0)
				{
					ans += "0";
					a--;
				}
				while (b > 0)
				{
					ans += "1";
					b--;
				}
			}
			else if(a>0&&b==0)
			{
				while (a > 0)
				{
					ans += "0";
					a--;
				}
			}
			else if(a==0&&b>0)
			{
				while (b > 0)
				{
					ans = "1"+ans;
					b--;
				}
			}
			cout << ans << endl;
		}
	}

	return 0;
}