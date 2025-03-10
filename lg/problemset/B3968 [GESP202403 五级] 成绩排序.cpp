#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

struct score
{
	int chinese, math, english, id;
	int ranking; // 新增字段，存储排名

	bool operator<(const score &a) const
	{
		if (chinese + math + english == a.chinese + a.math + a.english)
		{
			if (chinese + math == a.chinese + a.math)
			{
				return max(chinese, math) > max(a.chinese, a.math);
			}
			return chinese + math > a.chinese + a.math;
		}
		return chinese + math + english > a.chinese + a.math + a.english;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<score> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].chinese >> a[i].math >> a[i].english;
		a[i].id = i;
	}

	sort(a.begin(), a.end());

	a[0].ranking = 1;
	for (int i = 1; i < n; i++)
	{
		int total_cur = a[i].chinese + a[i].math + a[i].english;
		int total_prev = a[i - 1].chinese + a[i - 1].math + a[i - 1].english;
		int sum_cur = a[i].chinese + a[i].math;
		int sum_prev = a[i - 1].chinese + a[i - 1].math;
		int max_cur = max(a[i].chinese, a[i].math);
		int max_prev = max(a[i - 1].chinese, a[i - 1].math);
		if (total_cur == total_prev && sum_cur == sum_prev && max_cur == max_prev)
			a[i].ranking = a[i - 1].ranking;
		else
			a[i].ranking = i + 1;
	}

	vector<int> ans(n);
	for (auto s : a)
		ans[s.id] = s.ranking;

	for (int i = 0; i < n; i++)
		cout << ans[i] << endl;

	return 0;
}