#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct student
{
	string sign;
	string name;
	int score;
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<student> students(n);
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].sign >> students[i].name >> students[i].score;
		sum += students[i].score;
	}
	double ave = (double)sum / n;
	cout << ave << endl;

	for (int i = 0; i < n; i++)
	{
		if (students[i].score < ave)
		{
			cout << students[i].name << " " << students[i].sign << endl;
		}
	}

	return 0;
}