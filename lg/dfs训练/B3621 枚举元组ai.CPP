#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int a[100];
int n, k;
bool finished = false;

void printa() {
    for (int i = 1; i <= n; ++i) {
        cout << a[i];
        if (i != n) cout << " ";
    }
    cout << endl;
}

void solve(int pos) {
    if (finished) return;
    if (pos > n) {
        printa();
        return;
    }

    for (int i = 1; i <= k; ++i) {
        a[pos] = i;
        solve(pos + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    solve(1);

    return 0;
}