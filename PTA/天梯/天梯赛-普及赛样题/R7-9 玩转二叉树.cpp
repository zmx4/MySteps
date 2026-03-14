#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

vector<int> mid_order, pre_order;

// 建树并同时进行镜面反转
Node *buildTree(int preL, int preR, int inL, int inR)
{
    if (preL > preR)
        return nullptr;

    Node *root = new Node;
    root->val = pre_order[preL];

    // 在中序遍历中找到根节点的位置
    int k = inL;
    while (k <= inR && mid_order[k] != root->val)
    {
        k++;
    }

    int leftLen = k - inL; // 原左子树的节点个数

    // 镜面反转：将原来的左子树建在右边，原来的右子树建在左边
    root->right = buildTree(preL + 1, preL + leftLen, inL, k - 1);
    root->left = buildTree(preL + leftLen + 1, preR, k + 1, inR);

    return root;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    mid_order.resize(n);
    pre_order.resize(n);

    for (int i = 0; i < n; i++)
        cin >> mid_order[i];
    for (int i = 0; i < n; i++)
        cin >> pre_order[i];

    // 构建反转后的树
    Node *root = buildTree(0, n - 1, 0, n - 1);

    // BFS层序遍历
    vector<int> res;
    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        res.push_back(node->val);

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    // 格式化输出，行首尾及数字间格式限制
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}