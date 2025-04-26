
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

int MaxWidth(BiTree T);

int main()
{
	BiTree T = Create();
	printf("The max-width of the tree is %d.\n", MaxWidth(T));
	return 0;
}
/* 你的代码将被嵌在这里 */

int MaxWidth(BiTree T)
{
	if (T == NULL)
		return 0;
	BiTree queue[100];
	int head = 0, tail = 0;
	queue[tail++] = T;
	int maxw = 0;
	while (head < tail)
	{
		int sz = tail - head;
		if (sz > maxw)
			maxw = sz;
		for (int i = 0; i < sz; i++)
		{
			BiTree p = queue[head++];
			if (p->lchild)
				queue[tail++] = p->lchild;
			if (p->rchild)
				queue[tail++] = p->rchild;
		}
	}
	return maxw;
}