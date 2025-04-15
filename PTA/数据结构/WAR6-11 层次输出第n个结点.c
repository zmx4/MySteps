#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

void PrintNode(BiTree T, int n);
int main()
{
	BiTree T = Create();
	int n;
	scanf("%d", &n);
	printf("The %d-th node in levelorder is: ", n);
	PrintNode(T, n);
	printf("\n");
	return 0;
}
/* 你的代码将被嵌在这里 */

void PrintNode(BiTree T, int n)
{
	if(!T || n < 1)
		return;
	if(n == 1)
	{
		printf("%c", T->data);
		return;
	}
	PrintNode(T->lchild, n - 1);
	PrintNode(T->rchild, n - 1);
}