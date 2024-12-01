#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int x1, x2, x3;
	cin >> x1 >> x2 >> x3;

	// 将三个坐标存储到一个数组中，并对其进行排序
	vector<int> positions = {x1, x2, x3};
	sort(positions.begin(), positions.end());

	// 相遇点为中间的那个点，计算总移动距离
	int min_distance = (positions[2] - positions[1]) + (positions[1] - positions[0]);

	// 输出最小总移动距离
	cout << min_distance << endl;

	return 0;
}