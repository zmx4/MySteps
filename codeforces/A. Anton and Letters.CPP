#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);
	bool show[26] = {false};

	for (char c : s) {
		if (c >= 'a' && c <= 'z') {
			show[c - 'a'] = true;
		}
	}

	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (show[i]) {
			count++;
		}
	}

	cout << count << endl;
	return 0;
}