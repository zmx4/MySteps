#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
vector<pair<int, int>> v;
const int N = 300 + 10;
int n;
bool vis[N];
struct pair_hash
{
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ (hash2 << 1); // Combine the two hash values
	}
};
//70
unordered_set<pair<double, double>, pair_hash> st;
double ans = inf;
void dfs(double x, double y, int cnt, double sum)
{
	if(sum > ans) return;
	if (cnt == n)
	{
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			double tmp = sqrt(abs(x - v[i].first) * abs(x - v[i].first) + abs(y - v[i].second) * abs(y - v[i].second));
			dfs(v[i].first, v[i].second, cnt + 1, sum + tmp);
			vis[i] = false;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	// v.resize(n);
	for (int i = 0; i < n; i++)
	{
		// cin >> v[i].first >> v[i].second;
		double x, y;
		cin >> x >> y;
		if (!st.count(make_pair(x, y)))
		{
			v.push_back(make_pair(x, y));
			st.insert(make_pair(x, y));
		}
		else
		{
			n--;
		}
	}
	dfs(0.0, 0.0, 0, 0);
	cout << format("{:.2f}", ans) << endl;
	return 0;
}
// 90
/*
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<double,double>> cheese;
vector<bool> vis;
double best = 1e18;

// 计算两点之间的距离
double distanceBetween(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void dfs(double cx, double cy, int cnt, double sum) {
	// 剪枝：当前累计距离已不小于当前最优时，直接返回
	if(sum >= best) return;
	if(cnt == n) {
		best = min(best, sum);
		return;
	}
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			vis[i] = true;
			double d = distanceBetween(cx, cy, cheese[i].first, cheese[i].second);
			dfs(cheese[i].first, cheese[i].second, cnt+1, sum + d);
			vis[i] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cheese.resize(n);
	vis.assign(n, false);
	for(int i = 0; i < n; i++){
		cin >> cheese[i].first >> cheese[i].second;
	}

	// 从起点 (0,0) 开始
	dfs(0.0, 0.0, 0, 0.0);

	cout << fixed << setprecision(2) << best << "\n";
	return 0;
}
*/