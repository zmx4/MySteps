#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> post;
vector<int> tree;
int post_idx = 0;

void build(int u)
{
    if (u > n)
        return;
    build(u * 2);
    build(u * 2 + 1);
    tree[u] = post[post_idx++];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    post.resize(n);
    tree.resize(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    build(1);
    for (int i = 1; i <= n; i++)
    {
        cout << tree[i] << (i == n ? "" : " ");
    }

    return 0;
}