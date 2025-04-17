#include <bits/stdc++.h>
using namespace std;

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
} BiNode, *BiTree;

BiTree creat(int *pre, int *in, int n)
{
	if (n <= 0)
		return nullptr;
	BiTree T = new BiNode;
	T->data = pre[n - 1];
	int i;
	for (i = 0; i < n && pre[n - 1] != in[i]; i++)
		;
	T->lchild = creat(pre, in, i);
	T->rchild = creat(pre + i, in + 1 + i, n - i - 1);
	return T;
}
void preOrder(BiTree T)
{
	if (T)
	{
		cout << " " << T->data;
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
int main()
{
	int n;
	cin >> n;
	int pre[35], in[35];
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	for (int i = 0; i < n; i++)
		cin >> in[i];
}
// C version
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree create(int *post,int *in,int n)
{
	if(n<=0) return NULL;
	BiTree T=(BiTree)malloc(sizeof(BiTNode));
	T->data=post[n-1];
	int i;
	for(i=0;i<n && in[i]!=post[n-1];i++);
	T->lchild=create(post,in,i);
	T->rchild=create(post+i,in+i+1,n-i-1);
	return T;
}
void preOrder(BiTree T)
{
	if(T)
	{
		printf(" %d",T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}
void preOrder2(int *post,int *in,int n)
{
	if(n<=0) return;
	printf(" %d",post[n-1]);
	int i;
	for(i=0;i<n && in[i]!=post[n-1];i++);
	preOrder2(post,in,i);
	preOrder2(post+i,in+i+1,n-i-1);
}
int main()
{
	int n;
	scanf("%d",&n);
	int post[35]={0},in[35]={0};
	for(int i=0;i<n;i++) scanf("%d",&post[i]);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	printf("Preorder:");
	//BiTree T;
	//T=create(post,in,n);
	//preOrder(T);
	preOrder2(post,in,n);
	return 0;
}
*/