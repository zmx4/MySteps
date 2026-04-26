#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	string str;
	cin >> str;
	string ans = "";
	int a,b;cin >> a >> b;
	for(int i = a;i < str.size() - b;++i)ans+=str[i];
	cout << ans;
	
	
	
	return 0;
}
