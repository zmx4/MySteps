#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;
BSTree CreateBST();
/ *二叉排序树创建，由裁判实现，细节不表 * /
	BSTree SearchBST(BSTree T, ElemType e);
int main()
{
	BSTree T, result;
	ElemType n, e;
	T = CreateBST();
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &e);
		result = SearchBST(T, e);
		if (result)
			printf("%d is found\n", result->data);
		else
			printf("%d is not found\n", e);
	}
	return 0;
}
BSTree SearchBST(BSTree T, ElemType e)
{
	if (T->data == e)
		return T;
	if (e < T->data)
		return SearchBST(T->lchild, e);
	else
		return SearchBST(T->rchild, e);
}