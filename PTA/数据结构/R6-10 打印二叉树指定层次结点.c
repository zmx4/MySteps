
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

void PrintLevel(BiTree T, int n);

int main()
{
	int n;
	BiTree T = Create();
	scanf("%d", &n);
	PrintLevel(T, n);
	printf("\n");
	return 0;
}
/* 你的代码将被嵌在这里 */

void PrintLevel(BiTree T, int n)
{
	if(!T)
		return;
	if(n == 1)
	{
		printf("%c ", T->data);
		return;
	}
	PrintLevel(T->lchild, n - 1);
	PrintLevel(T->rchild, n - 1);
}