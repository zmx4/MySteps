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
		int a, b, c;cin>>a>>b>>c;
		int sum = a + b + c;
		int min = std::min(a, std::min(b, c)),max = std::max(a, std::max(b, c));
		int mid = sum - min - max;

		if(mid+min == max)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}