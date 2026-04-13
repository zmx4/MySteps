#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
vector<int> pre,in;
struct node
{
    int val;
    node *l, *r;
    node(int v):val(v),l(nullptr),r(nullptr){}
};
void build(node *&root, int prel,int prer,int inl,int inr)
{
    if (prel > prer || inl > inr)
        return;
    int val = pre[prel];
    root = new node(val);
    int pos = inl;
    while (in[pos] != val)
        pos++;
    int leftnum = pos - inl;
    build(root->l, prel + 1, prel + leftnum, inl, pos - 1);
    build(root->r, prel + leftnum + 1, prer, pos + 1, inr);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n;
    cin >> n;
    pre.resize(n+1);
    in.resize(n+1);
    for(int i = 1; i <= n;i++)cin >> in[i];
    for(int i = 1; i <= n;i++)cin >> pre[i];

    node *root = nullptr;
    build(root, 1, n, 1, n);
    queue<node*> q;
    q.push(root);
    bool isFirst = true;
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        if (!isFirst)
            cout << " ";
        cout << t->val;
        isFirst = false;
        if(t->r)
            q.push(t->r);
        if(t->l)
            q.push(t->l);
    }

    return 0;
}