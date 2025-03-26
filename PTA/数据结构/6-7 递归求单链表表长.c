
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */

int Length(LinkList L);

int main()
{
	LinkList L = Create();
	printf("%d\n", Length(L));
	return 0;
}

/* 你的代码将被嵌在这里 */
int Length(LinkList L)
{
	if(!L)
		return 0;
	if(L->next==NULL)
		return 1;
	return Length(L->next) + 1;
}