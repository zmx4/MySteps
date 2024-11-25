#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

// 计算原始数列的最大值
long long calculateOriginalMax(const vector<int>& arr) {
	long long result = 1;
	bool hasOne = false;
	int onesCount = 0;

	for (int num : arr) {
		if (num == 1) {
			onesCount++;
			hasOne = true;
		} else {
			if (hasOne) {
				result = (result * (onesCount + 1)) % MOD;
				onesCount = 0;
				hasOne = false;
			}
			result = (result * num) % MOD;
		}
	}

	if (hasOne) {
		result = (result * (onesCount + 1)) % MOD;
	}

	return result;
}

// 计算重排数列的最大值
long long calculateRearrangedMax(const vector<int>& arr) {
	vector<int> sortedArr = arr;
	sort(sortedArr.begin(), sortedArr.end(), greater<int>());

	long long result = 1;
	int onesCount = 0;

	for (int num : sortedArr) {
		if (num == 1) {
			onesCount++;
		} else {
			if (onesCount > 0) {
				result = (result * (onesCount + 1)) % MOD;
				onesCount = 0;
			}
			result = (result * num) % MOD;
		}
	}

	if (onesCount > 0) {
		result = (result * (onesCount + 1)) % MOD;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	long long originalMax = calculateOriginalMax(arr);
	long long rearrangedMax = calculateRearrangedMax(arr);

	cout << originalMax << " " << rearrangedMax << endl;

	return 0;
}