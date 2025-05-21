
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;
BSTree CreateBST(); /* 二叉排序树创建，由裁判实现，细节不表 */
BSTree FindMin(BSTree T);
BSTree FindMax(BSTree T);
void Inorder(BSTree T); /* 中序遍历，由裁判实现，细节不表 */

int main()
{
	BSTree T, MinP, MaxP;
	ElemType n, e;
	T = CreateBST();
	printf("Inorder:");
	Inorder(T);
	printf("\n");
	MinP = FindMin(T);
	MaxP = FindMax(T);
	if (MinP)
		printf("%d is the smallest key\n", MinP->data);
	if (MaxP)
		printf("%d is the largest key\n", MaxP->data);
	return 0;
}
/* 你的代码将被嵌在这里 */

BSTree FindMin(BSTree T)
{
	if (T == NULL)
		return NULL;
	while (T->lchild != NULL)
		T = T->lchild;
	return T;
}
BSTree FindMax(BSTree T)
{
	if (T == NULL)
		return NULL;
	while (T->rchild != NULL)
		T = T->rchild;
	return T;
}