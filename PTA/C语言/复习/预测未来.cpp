#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<long long> hangSum(n + 1, 0), lieSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            hangSum[i] += (i + j);
            lieSum[j] += (i + j);
        }
    }

    vector<bool> hangZeroed(n + 1, false), lieZeroed(n + 1, false);

    while (q--) {
        char type;
        int index;
        cin >> type >> index;
        
        if (type == 'R') {
            if (!hangZeroed[index]) {
                cout << hangSum[index] << '\n';
                hangZeroed[index] = true;
                for (int j = 1; j <= n; ++j) {
                    if (!lieZeroed[j]) {
                        lieSum[j] -= (index + j);
                    }
                }
            } else {
                cout << 0 << '\n';
            }
        } else if (type == 'C') {
            if (!lieZeroed[index]) {
                cout << lieSum[index] << '\n';
                lieZeroed[index] = true;
                for (int i = 1; i <= n; ++i) {
                    if (!hangZeroed[i]) {
                        hangSum[i] -= (i + index);
                    }
                }
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}