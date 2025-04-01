#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

struct student
{
	string id;
	string name;
	int score;
	int index;
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n,order;
	cin >> n >> order;
	student stu[n+1];
	for (int i = 1; i <= n; i++)
	{
		cin >> stu[i].id >> stu[i].name >> stu[i].score;
		stu[i].index = i;
	}
	sort(stu+1,stu+n+1,[&](student a,student b){
		if (order == 1) return a.id < b.id;
		else if (order == 2)
		{
			if(a.name!=b.name)return a.name < b.name;
			else return a.id < b.id;
		}
		else if (order == 3)
		{
			if (a.score != b.score) return a.score < b.score;
			else return a.id < b.id;
		}
		else return a.index < b.index;
	});
	for (int i = 1; i <= n; i++)
	{
		cout << stu[i].id << " " << stu[i].name << " " << stu[i].score << endl;
	}








	return 0;
}