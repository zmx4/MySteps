#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 500000 + 5;
int lc[MAXN], rc[MAXN], parent_arr[MAXN];

inline void solve()
{
    int n;
    cin >> n;
    // 初始化左右孩子和父数组
    for (int i = 1; i <= n; i++)
    {
        lc[i] = rc[i] = parent_arr[i] = 0;
    }
    // 读入 n-1 条边：u 的父节点是 v，op=0 左子，op=1 右子
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, op;
        cin >> u >> v >> op;
        parent_arr[u] = v;
        if (op == 0)
            lc[v] = u;
        else
            rc[v] = u;
    }
    // 找根节点
    int root = 1;
    while (parent_arr[root] != 0)
        root++;

    // 1. 先序遍历（根→左→右）
    {
        vector<int> stk;
        stk.reserve(n);
        stk.push_back(root);
        bool first = true;
        while (!stk.empty())
        {
            int u = stk.back();
            stk.pop_back();
            if (!first)
                cout << ' ';
            first = false;
            cout << u;
            // 右子先压，左子后压，这样先访问左子
            if (rc[u])
                stk.push_back(rc[u]);
            if (lc[u])
                stk.push_back(lc[u]);
        }
        cout << '\n';
    }

    // 2. 中序遍历（左→根→右）
    {
        vector<int> stk;
        stk.reserve(n);
        int u = root;
        bool first = true;
        while (u || !stk.empty())
        {
            while (u)
            {
                stk.push_back(u);
                u = lc[u];
            }
            u = stk.back();
            stk.pop_back();
            if (!first)
                cout << ' ';
            first = false;
            cout << u;
            u = rc[u];
        }
        cout << '\n';
    }

    // 3. 后序遍历（左→右→根）— 两栈法
    {
        vector<int> s1, s2;
        s1.reserve(n);
        s2.reserve(n);
        s1.push_back(root);
        while (!s1.empty())
        {
            int u = s1.back();
            s1.pop_back();
            s2.push_back(u);
            if (lc[u])
                s1.push_back(lc[u]);
            if (rc[u])
                s1.push_back(rc[u]);
        }
        bool first = true;
        for (int i = (int)s2.size() - 1; i >= 0; i--)
        {
            if (!first)
                cout << ' ';
            first = false;
            cout << s2[i];
        }
        cout << '\n';
    }

    // 4. 层序遍历（BFS）
    {
        queue<int> q;
        q.push(root);
        bool first = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (!first)
                cout << ' ';
            first = false;
            cout << u;
            if (lc[u])
                q.push(lc[u]);
            if (rc[u])
                q.push(rc[u]);
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}