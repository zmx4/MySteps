#include<bits/stdc++.h>
#define int long long
using ll = long long;
using ull = unsigned long long;
using namespace std;
signed main()
{
	int T,S,t;
	cin>>T>>S>>t;
	if(S==1)
	{
		if(T>=35 && t>=33)
		{
			cout<<"Bu Tie"<<endl<<T<<endl;
		}
		else if(T>=35 &&  t <= 33)
		{
			cout<<"Bu Re"<<endl<<t<<endl;
		}
		else
		{
			cout<<"Shu Shi"<<endl<<t<<endl;
		}
	}
	else
	{
		if(T>=35&&t>=33)
		{
			cout<<"Shi Nei"<<endl<<T<<endl;
		}
		else if(t<33&&T>=35)
		{
			cout<<"Bu Re"<<endl<<t<<endl;
		}
		else if(t<33&&T<33)
		{
			cout<<"Shu Shi"<<endl<<t<<endl;
		}
	}
}