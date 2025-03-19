#include <bits/stdc++.h>
using namespace std;

long long findMinN(long long k) {
    long long low = 1, high = 1e18; // 设置一个足够大的上限
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;
        cout << findMinN(k) << endl;
    }
    return 0;
}