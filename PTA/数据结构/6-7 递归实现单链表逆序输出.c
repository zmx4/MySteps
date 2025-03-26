
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */
void Reverse(LinkList L);
int main()
{
	LinkList L = Create();
	Reverse(L);
	return 0;
}

/* 请在这里填写答案 */
void Reverse(LinkList L)
{
	if(L  == NULL)
	{
		return;
	}
	if (L->next == NULL)
	{
		printf("%d ", L->data);
		return;
	}
	//LinkList p = L->next;
	Reverse(L->next);
	printf("%d ", L->data);
}