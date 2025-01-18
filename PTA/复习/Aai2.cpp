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

        vector<int> a(n + 1); // 用于存储输入的数据
        map<int, int> cnt;    // 使用 map 存储每个数字出现的次数

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // 计算每个数字在所有子数组中出现的次数
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                cnt[a[j]]++;
            }
        }

        // 输出结果
        for (int i = 1; i <= m; i++) {
            cout << cnt[i] << " \n"[i == m]; // 如果是最后一个元素，则换行
        }
    }

    return 0;
}