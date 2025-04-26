
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct BiTNode
{
	ElementType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

int NodeCount(BiTree T, int i);

int main()
{
	int n;
	BiTree T = Create();
	scanf("%d", &n);
	printf("The num of  nodes in %d-th level is %d.\n", n, NodeCount(T, n));
	return 0;
}
/* 你的代码将被嵌在这里 */

int NodeCount(BiTree T, int i)
{
	if (T == NULL || i < 1)
		return 0;
	if (i == 1)
		return 1;
	else
		return NodeCount(T->lchild, i - 1) + NodeCount(T->rchild, i - 1);
}