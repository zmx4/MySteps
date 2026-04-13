#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
struct node
{
    int val;
    node *l, *r;
    node(int v):val(v),l(nullptr),r(nullptr){}
};
vector<int> mid, nxt;
int n;
void build(node *&root, int nxtl,int nxtr,int inl,int inr)
{
    if (nxtl > nxtr || inl > inr)
        return;
    int val = nxt[nxtr];
    root = new node(val);
    int pos = inl;
    while (mid[pos] != val)
        pos++;
    int leftnum = pos - inl;
    build(root->l, nxtl, nxtl + leftnum - 1, inl, pos - 1);
    build(root->r, nxtl + leftnum, nxtr - 1, pos + 1, inr);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin >> n;
    mid.resize(n+1);
    nxt.resize(n+1);
    for(int i = 1; i <= n;i++)
        cin >> nxt[i];
    for(int i = 1; i <= n;i++)
        cin >> mid[i];

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
        if(t->l)
            q.push(t->l);
        if(t->r)
            q.push(t->r);
    }

    return 0;
}