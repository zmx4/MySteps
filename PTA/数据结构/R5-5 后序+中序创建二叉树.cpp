#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char ElementType;
typedef struct BiTNode
{
	ElementType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

BiTree CreatBinTree(char *post, char *in, int n);
void preorder(BiTree T);

int main()
{
	BiTree T;
	char postlist[100];
	char inlist[100];
	int length;
	scanf("%s", postlist);
	scanf("%s", inlist);
	length = strlen(postlist);
	T = CreatBinTree(postlist, inlist, length);
	preorder(T);
	return 0;
}
void preorder(BiTree T)
{
	if (T)
	{
		printf("%c", T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
BiTree CreatBinTree(char *post, char *in, int n)
{
	BiTree T;
	int i;
	if (n <= 0)
		return NULL;
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = post[n - 1];
	for (i = 0; in[i] != post[n - 1]; i++)
		;
	T->lchild = CreatBinTree(post, in, i);
	T->rchild = CreatBinTree(post + i, in + i + 1, n - i - 1);
	return T;
}