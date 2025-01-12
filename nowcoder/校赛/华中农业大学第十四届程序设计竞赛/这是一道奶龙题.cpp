#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;cin>>n;
	string a;cin>>a;
	int sign = 0;
	for(int i = 0;i <= a.length();i++)
	{
		if(a[i] == 'e'&& sign == 0) sign++;
		if(a[i] == 'z'&& sign == 1) sign++;
	}
	if(sign == 2) cout<<"easy"<<endl;
	else cout<<"hard"<<endl;
	return 0;
}