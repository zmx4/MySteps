
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

int OperandCount(BiTree T);

int main()
{
	BiTree T = Create();

	printf("%d\n", OperandCount(T));
	return 0;
}
/* 你的代码将被嵌在这里 */

int OperandCount(BiTree T)
{
	if (!T)
		return 0;
	if (T->data == '+' || T->data == '-' || T->data == '*' || T->data == '/')
		return OperandCount(T->lchild) + OperandCount(T->rchild);
	else
		return 1;
}