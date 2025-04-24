
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

int OperatorCount(BiTree T);

int main()
{
	BiTree T = Create();

	printf("%d\n", OperatorCount(T));
	return 0;
}
/* 你的代码将被嵌在这里 */

int OperatorCount(BiTree T)
{
	if (!T)
		return 0;
	if (T->data == '+' || T->data == '-' || T->data == '*' || T->data == '/')
		return OperatorCount(T->lchild) + OperatorCount(T->rchild) + 1;
	else
		return OperatorCount(T->lchild) + OperatorCount(T->rchild);
}