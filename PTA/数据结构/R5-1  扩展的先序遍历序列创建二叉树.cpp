#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct BiTNode
{
	ElementType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

BiTree CreatBinTree();
void preorder(BiTree T);

int main()
{
	BiTree T = CreatBinTree();
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
BiTree CreatBinTree()
{
	char ch;
	BiTree T;
	scanf("%c", &ch);
	if (ch == '#')
		return NULL;
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = ch;
	T->lchild = CreatBinTree();
	T->rchild = CreatBinTree();
	return T;
}