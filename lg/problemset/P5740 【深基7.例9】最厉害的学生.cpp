#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

struct student
{
	string name;
	int a, b, c;
	int total;
	int id;
};
bool cmp(const student &a, const student &b)
{
	if(a.total != b.total)
		return a.total > b.total;
	return a.id < b.id;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<student> v(n);
	for(auto &i : v)
	{
		cin >> i.name >> i.a >> i.b >> i.c;
		i.total = i.a + i.b + i.c;
		i.id = &i - &v[0];
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].name << " " << v[0].a << " " << v[0].b << " " << v[0].c << endl;
	return 0;
}