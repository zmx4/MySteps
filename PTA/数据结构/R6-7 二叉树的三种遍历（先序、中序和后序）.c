
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

void Preorder(BiTree T);
void Inorder(BiTree T);
void Postorder(BiTree T);

int main()
{
	BiTree T = Create();
	printf("Preorder:");
	Preorder(T);
	printf("\n");
	printf("Inorder:");
	Inorder(T);
	printf("\n");
	printf("Postorder:");
	Postorder(T);
	printf("\n");
	return 0;
}
/* 你的代码将被嵌在这里 */

void Preorder(BiTree T)
{
	if (T == NULL)
		return;
	printf("%c", T->data);
	Preorder(T->lchild);
	Preorder(T->rchild);
}
void Inorder(BiTree T)
{
	if (T == NULL)
		return;
	Inorder(T->lchild);
	printf("%c", T->data);
	Inorder(T->rchild);
}
void Postorder(BiTree T)
{
	if (T == NULL)
		return;
	Postorder(T->lchild);
	Postorder(T->rchild);
	printf("%c", T->data);
}