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

BiTree CreatBinTree(char *pre, char *in, int n);
void postorder(BiTree T);

int main()
{
	BiTree T;
	char prelist[100];
	char inlist[100];
	int length;
	scanf("%s", prelist);
	scanf("%s", inlist);
	length = strlen(prelist);
	T = CreatBinTree(prelist, inlist, length);
	postorder(T);
	return 0;
}
void postorder(BiTree T)
{
	if (T)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c", T->data);
	}
}
BiTree CreatBinTree(char *pre, char *in, int n)
{
	BiTree T;
	int i;
	if (n <= 0)
		return NULL;
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = pre[0];
	for (i = 0; in[i] != pre[0]; i++)
		;
	T->lchild = CreatBinTree(pre + 1, in, i);
	T->rchild = CreatBinTree(pre + i + 1, in + i + 1, n - i - 1);
	return T;
}