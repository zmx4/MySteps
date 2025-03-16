#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

struct Student
{
	int id;
	int chinese, math, english;
	int total;
	bool operator<(const Student &rhs) const
	{
		if (total == rhs.total)
		{
			if (chinese == rhs.chinese)
			{
				return id < rhs.id;
			}
			return chinese > rhs.chinese;
		}
		return total > rhs.total;
	}
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<Student> students(n);
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].chinese >> students[i].math >> students[i].english;
		students[i].id = i + 1;
		students[i].total = students[i].chinese + students[i].math + students[i].english;
	}
	sort(students.begin(), students.end());
	for (int i = 0; i < 5; i++)
	{
		cout << students[i].id << " " << students[i].total << endl;
	}

	return 0;
}