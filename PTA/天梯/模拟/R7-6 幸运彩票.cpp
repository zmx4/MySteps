#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;
bool check(int a,int b)
{
	int suma = 0,sumb = 0;
	//cout<<a<<" "<<b<<endl;
	while(a)
	{
		suma+=a%10;
		a/=10;
	}
	while(b)
	{
		sumb+=b%10;
		b/=10;
	}
	if(suma==sumb)return true;
	else return false;
}
signed main()
{
  ios::sync_with_stdio(false);cin.tie(nullptr);
  int n;cin>>n;
  while(n--)
	{
		string s;
		cin>>s;
		int a = stoi(s.substr(0,3)),b=stoi(s.substr(3,3));
		if(check(a,b))cout<<"You are lucky!"<<endl;
		else cout<<"Wish you good luck."<<endl;
	}

  return 0;
}