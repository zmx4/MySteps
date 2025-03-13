#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
struct Person
{
	string id;
	char sex;
	string fid, mid;
};

int main()
{
	int N;
	cin >> N;
	unordered_map<string, Person> people;
	for (int i = 0; i < N; i++)
	{
		Person p;
		cin >> p.id >> p.sex >> p.fid >> p.mid;
		people[p.id] = p;
	}
	int k;
	cin >> k;
	auto bfs = [&](const string &id) -> unordered_map<string, int>
	{
		unordered_map<string, int> dist; // 存储到每个祖先的代际距离
		queue<pair<string, int>> q;
		q.push({id, 0});
		while (!q.empty())
		{
			auto [cid, d] = q.front();
			q.pop();
			if (dist.count(cid))
				continue;
			dist[cid] = d; // 记录到该祖先的代际距离
			if (d < 4)
			{
				if (people[cid].fid != "-1")
					q.push({people[cid].fid, d + 1});
				if (people[cid].mid != "-1")
					q.push({people[cid].mid, d + 1});
			}
		}
		return dist;
	};

	while(k--)
	{
		string id1, id2;
		cin >> id1 >> id2;
		if (people[id1].sex == people[id2].sex)
		{
			cout << "Never Mind" << "\n";
		}
		else
		{
			auto zu1 = bfs(id1);
			auto zu2 = bfs(id2);
			bool related = false;
			for (auto &[ancestor, d1] : zu1)
			{
				if (zu2.count(ancestor))
				{
					int d2 = zu2[ancestor];
					if (d1 + d2 <= 5)
					{ // 五服以内判定：代际距离之和不超过5
						related = true;
						break;
					}
				}
			}
			if(related)
			{
				cout << "No" << endl;
			}
			else
			{
				cout << "Yes" << endl;
			}
		}
	}
	
}