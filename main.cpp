#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int low = 0, high = INT_MAX;
	while (N--)
	{
		int A, B;
		cin >> A >> B;
		int cur_low = A / (B + 1) + 1; // 最小可能的 V
		int cur_high = A / B;		   // 最大可能的 V
		low = max(low, cur_low);
		high = min(high, cur_high);
	}
	cout << low << " " << high << "\n";
	return 0;
}