#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>>n;
	string s;
	cin>>s;
	int cnt = 0;
	string str = "wow";
	int ans = 0;
	for(int i = 0; i < n - 1; i++)
	{
		string temp = s.substr(i, 3);
		if(temp == str)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}