#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;cin>>n;
	string s1,s2;cin>>s1>>s2;
	bool flag = true;
	//if(s1[0]=='1'&&s2[1]=='1')flag = false;
	string str1 = "",str2="";
	for (int i = 0; i < n;i++)
	{
		if(i%2==0)
		{
			str1 += s1[i];
			str2 += s2[i];
		}
		else
		{
			str1 += s2[i];
			str2 += s1[i];
		}
	}
	int cnt1 = 0, cnt0 = 0;
	for (int i = 0; i < n;i++)
	{
		if(str1[i]=='1')
			cnt1++;
		else
			cnt0++;
	}
	if(cnt0<(n+1)/2)
		flag = false;
	cnt1 = 0, cnt0 = 0;
	for (int i = 0; i < n; i++)
	{
		if (str2[i] == '1')
			cnt1++;
		else
			cnt0++;
	}
	if ( cnt0 < n/2)
		flag = false;
	// cout<<str<<endl;
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
/*
02
13
13
02

*/
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}