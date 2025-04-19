#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using namespace std;
signed main()
{
	string s;cin>>s;
	vector<int>a(s.size(),0);
	map<int,int>mp,cnt;
	int sum = 0;
	for(int i = 0;i < 26;i++)cin>>mp[i];
	for(int i = 0;i < s.size();i++)
	{
		a[i]=s[i]-'a';
		sum+=mp[a[i]];
		cnt[a[i]]++;
	}
	for(int i = 0;i < 26;i++)
	{
		cout<<cnt[i];
		if(i!=25)cout<<" ";
	}
	cout<<endl;
	cout<<sum<<endl;
	
}