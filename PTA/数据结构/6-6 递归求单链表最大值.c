
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */

LinkList MaxP(LinkList L);

int main()
{
	LinkList L, p;
	ElemType e;
	L = Create();
	p = MaxP(L);
	if (p)
		printf("%d\n", p->data);
	else
		printf("NULL");
	return 0;
}

/* 你的代码将被嵌在这里 */
LinkList MaxP(LinkList L)
{
	if (L == NULL)
		return NULL;
	if (L->next == NULL)
		return L;
	LinkList maxRest = MaxP(L->next);
	return (L->data > maxRest->data) ? L : maxRest;
}