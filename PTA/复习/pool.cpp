#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int parent[MAXN], size[MAXN], totalWater[MAXN];

// 查找根节点，并进行路径压缩
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 合并两个集合
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
        size[rootY] += size[rootX];
        totalWater[rootY] += totalWater[rootX];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 初始化并查集
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
        cin >> totalWater[i];
    }

    while (m--) {
        int operate;
        cin >> operate;

        if (operate == 1) {
            int a, b;
            cin >> a >> b;
            for (int i = a; i < b; i++) {
                unite(i, i + 1);
            }
        } else if (operate == 2) {
            int s;
            cin >> s;
            int root = find(s);
            double average = totalWater[root] / size[root];
            cout << fixed << setprecision(10) << average << '\n';
        }
    }

    return 0;
}