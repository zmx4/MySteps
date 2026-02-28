#include <iostream>
#include <algorithm>

using namespace std;

// 增加栈大小限制，防止在深搜时爆栈（针对 Windows MSVC），对于 MinGW 可能需要 -Wl,--stack 编译参数
#pragma comment(linker, "/STACK:102400000,102400000")

const int MAXN = 1005;
const int MAX_NODES = MAXN * MAXN;

int n, m;
int grid[MAXN][MAXN];
int id[MAXN][MAXN];
int node_cnt = 0;

struct Edge {
    int to;
    int next;
} edge[MAX_NODES * 5];
int head[MAX_NODES];
int tot = 0;

void add(int u, int v) {
    edge[++tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot;
}

// dfn: DFS时间戳
// low: 追溯值
// sz: DFS树中以 u 为根的子树包含的真实白色格子数量
int dfn[MAX_NODES], low[MAX_NODES], sz[MAX_NODES];
int timer = 0;
int max_blocked = 0;

void dfs(int u, int fa) {
    dfn[u] = low[u] = ++timer;
    sz[u] = 1; 

    int blocked_sum = 0;

    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) continue;

        if (!dfn[v]) {
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);

            // 判断割点条件：
            // 如果 v 无法通过反向边追溯到 u 的祖先（即 low[v] >= dfn[u]），
            // 说明 v 所在的子树主要依赖 u 连接到上层（即连接到包含 0 的区域）。
            if (u != 0 && low[v] >= dfn[u]) {
                blocked_sum += sz[v];
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (u != 0) {
        if (blocked_sum > max_blocked) {
            max_blocked = blocked_sum;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    int initial_black = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 0) {
                // 给白色格子编号
                id[i][j] = ++node_cnt;
            } else {
                initial_black++;
            }
        }
    }

    // 建立图结构
    // 节点 1 ~ node_cnt 是真实的白色格子
    // 节点 0 是代表整个边界的虚拟节点
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 0) {
                int u = id[i][j];
                
                // 如果是位于边界上的白色格子，连接到虚拟边界节点 0
                if (i == 1 || i == n || j == 1 || j == m) {
                    add(0, u);
                    add(u, 0);
                }

                // 内部连边，因为是遍历，只需向右和向下连边
                if (j + 1 <= m && grid[i][j+1] == 0) {
                    int v = id[i][j+1];
                    add(u, v);
                    add(v, u);
                }
                if (i + 1 <= n && grid[i+1][j] == 0) {
                    int v = id[i+1][j];
                    add(u, v);
                    add(v, u);
                }
            }
        }
    }

    if (node_cnt > 0) {
        dfs(0, -1);
    }

    // 最终黑色格子最大总数 = 初始黑色数目 + 1 (主动涂黑) + 因断连被动变黑
    cout << initial_black + 1 + max_blocked << endl;

    return 0;
}