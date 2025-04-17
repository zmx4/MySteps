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
//other vision
/*
#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
typedef struct BiTNode
{
	char data;
	BiTNode *lchild;
	BiTNode *rchild;
	int level;
}BiNode,*BiTree;
BiTree build(char *pre,char *in,int n)
{
	if(n==0)return nullptr;
	BiTree T = new BiNode;
	T->data = pre[0];
	int i = 0;
	for(;i<n&&in[i]!=pre[0];i++);
	T->lchild = build(pre+1,in,i);
	T->rchild = build(pre+i+1,in+i+1,n-i-1);
	return T;
}
int depth(BiTree T)
{
	if(!T)return 0;
	int ld = depth(T->lchild);
	int rd = depth(T->rchild);
	return ld>=rd?ld+1:rd+1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	char pre[55],in[55];
	cin>>pre>>in;
	BiTree T =  build(pre,in,n);

	cout<<depth(T)<<endl;

	return 0;
}
*/
//C version
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree create(char *pre,char *in,int n)
{
	if(n<=0) return NULL;
	BiTree T=(BiTree)malloc(sizeof(BiTNode));
	T->data=pre[0];
	int i;
	for(i=0;i<n && in[i]!=pre[0];i++);
	T->lchild=create(pre+1,in,i);
	T->rchild=create(pre+1+i,in+i+1,n-i-1);
	return T;
}
int depth(BiTree T)
{
	if(!T) return 0;
	int ld=depth(T->lchild);
	int rd=depth(T->rchild);
	return ld>=rd?ld+1:rd+1;
}
int depth2(char *pre,char *in,int n)
{
	if(n<=0) return 0;
	int i;
	for(i=0;i<n && in[i]!=pre[0];i++);
	int ld=depth2(pre+1,in,i);
	int rd=depth2(pre+1+i,in+i+1,n-i-1);
	return ld>=rd?ld+1:rd+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	char pre[55]={0},in[55]={0};
	scanf("%s%s",pre,in);
	//printf("%s\n%s\n",pre,in);
	//BiTree T;
	//T=create(pre,in,n);
	//int dh=depth(T);
	int dh=depth2(pre,in,n);
	printf("%d\n",dh);
	return 0;
}
*/