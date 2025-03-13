#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct User
{
	string name;
	int uniqueTags;
	double avgFrequency;
};

bool compareUsers(const User &u1, const User &u2)
{
	if (u1.uniqueTags != u2.uniqueTags)
	{
		return u1.uniqueTags > u2.uniqueTags;
	}
	else
	{
		return u1.avgFrequency < u2.avgFrequency;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<User> users(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> users[i].name;
		int K;
		cin >> K;
		map<int, int> tagFrequency;
		int totalFrequency = 0;
		for (int j = 0; j < K; ++j)
		{
			int tag;
			cin >> tag;
			if (tagFrequency[tag] == 0)
			{
				users[i].uniqueTags++;
			}
			tagFrequency[tag]++;
			totalFrequency += tagFrequency[tag];
		}
		users[i].avgFrequency = static_cast<double>(totalFrequency) / users[i].uniqueTags;
	}

	sort(users.begin(), users.end(), compareUsers);
	vector<string> ans;
	for (int i = 0; i < 3 && i < N; ++i)
	{
		// cout << users[i].name;
		// if (i < 2)
		// 	cout << " ";
		ans.push_back(users[i].name);
	}
	for (int i = 3 - min(3, N); i > 0; --i)
	{
		// cout << " -";
		ans.push_back("-");
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;

	return 0;
}