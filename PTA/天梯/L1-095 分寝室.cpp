#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int girls, boys, rooms;
	cin>>girls>>boys>>rooms;
	int bestSolution =INT_MAX;
	int bestBoys = 0;
	int bestGirl = 0;
	for (int i = 1; i < rooms; i++)
	{
		int g = rooms - i;
		int b = i;
		if(girls%g!=0||boys % b!=0)continue;
		int rg = girls / g,rb = boys / b;
		if(rg==1||rb==1)continue;
		if(abs(rg-rb)<bestSolution)
		{
			bestSolution = abs(rg-rb);
			bestBoys = b;
			bestGirl = g;
		}
	}
	if(bestSolution==INT_MAX)
		cout<<"No Solution"<<endl;
	else
		cout<<bestGirl<<" "<<bestBoys<<endl;
	return 0;
}