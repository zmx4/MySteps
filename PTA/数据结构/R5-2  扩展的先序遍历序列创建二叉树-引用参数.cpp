#include <stdio.h>
#include <stdlib.h>
typedef char ElementType;
typedef struct BiTNode
{
	ElementType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

void CreatBinTree(BiTree &T);
void preorder(BiTree T);

int main()
{
	BiTree T;
	CreatBinTree(T);
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
void CreatBinTree(BiTree &T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		T = NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		CreatBinTree(T->lchild);
		CreatBinTree(T->rchild);
	}
}