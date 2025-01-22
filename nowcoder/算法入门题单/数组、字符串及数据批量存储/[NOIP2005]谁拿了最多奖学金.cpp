#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int N;cin>>N;
	map<string,int> prize;
	ll sum = 0;
	while(N--)
	{
		string name;
		int finalScore, classScore, paperNum;
		char isLeader, isWest;
		int prizeNum = 0;
		cin>>name>>finalScore>>classScore>>isLeader>>isWest>>paperNum;
		if(finalScore>80&&paperNum>=1)
		{
			prizeNum+=8000;
		}
		if(finalScore>85&&classScore>80)
		{
			prizeNum+=4000;
		}
		if(finalScore>90)
		{
			prizeNum+=2000;
		}
		if(finalScore>85&&isWest=='Y')
		{
			prizeNum+=1000;
		}
		if(classScore>80&&isLeader=='Y')
		{
			prizeNum+=850;
		}
		prize[name]=prizeNum;
		sum+=prizeNum;
	}
	ll maxPrize = 0;
	string maxName;
	for(auto i:prize)
	{
		if(i.second>maxPrize)
		{
			maxPrize=i.second;
			maxName=i.first;
		}
	}
	cout<<maxName<<endl<<maxPrize<<endl;
	cout<<sum<<endl;
	return 0;
}