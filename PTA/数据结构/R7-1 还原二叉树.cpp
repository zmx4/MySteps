#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
struct BiTNode
{
	char data;
	BiTNode *lchild;
	BiTNode *rchild;
	int level;
};
BiTNode *buildTree(const string &pre, const string &inorder)
{
	if (pre.empty() || inorder.empty())
		return nullptr;
	BiTNode *root = new BiTNode;
	root->data = pre[0];
	root->lchild = root->rchild = nullptr;

	int pos = inorder.find(pre[0]);
	string leftIn = inorder.substr(0, pos);
	string rightIn = inorder.substr(pos + 1);
	string leftPre = pre.substr(1, leftIn.size());
	string rightPre = pre.substr(1 + leftIn.size());

	root->lchild = buildTree(leftPre, leftIn);
	root->rchild = buildTree(rightPre, rightIn);

	return root;
}

int getHeight(BiTNode *root)
{
	if (!root)
		return 0;
	int leftHeight = getHeight(root->lchild);
	int rightHeight = getHeight(root->rchild);
	return max(leftHeight, rightHeight) + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string pre, inorder;
	cin >> pre >> inorder;

	BiTNode *T = buildTree(pre, inorder);
	cout << getHeight(T) << endl;

	return 0;
}