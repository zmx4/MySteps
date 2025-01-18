#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int qwe;
    cin >> qwe;

    while (qwe--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n + 1); // 类似于开一个 a[n + 1] 的数组
        vector<int> cnt(m + 1, 0); // 初始化为 0

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            cnt[a[i]] += (n - i + 1); // 计算每个元素在所有子序列中出现的次数
        }

        for (int i = 1; i <= m; i++) {
            cout << cnt[i] << " \n"[i == m];
        }
    }

    return 0;
}