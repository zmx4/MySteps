#include <bits/stdc++.h>
using namespace std;
typedef struct BiTNode
{
	int data;
	BiTNode *lchild, *rchild;
} BiNode, *BiTree;
BiTree build(int *post, int *in, int n)
{
	if (n <= 0)
		return nullptr;
	BiTree T = new BiNode;
	T->data = post[n - 1];
	int i;
	for (i = 0; i < n && post[n - 1] != in[i]; i++)
		;
	T->lchild = build(post, in, i);
	T->rchild = build(post + i, in + i + 1, n - i - 1);
	return T;
}

int main()
{
	int n;
	cin >> n;
	int post[50], in[50];
	for (int i = 0; i < n; i++)
		cin >> post[i];
	for (int i = 0; i < n; i++)
		cin >> in[i];
	BiTree T = build(post, in, n);
	queue<BiTree> q;
	q.push(T);
	vector<int> ans;
	while (!q.empty())
	{
		BiTree t = q.front();
		q.pop();
		ans.push_back(t->data);
		if (t->lchild)q.push(t->lchild);
		if (t->rchild)q.push(t->rchild);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i < n - 1)
			cout << " ";
	}
}