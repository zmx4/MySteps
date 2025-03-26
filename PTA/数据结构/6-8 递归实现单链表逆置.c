
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
	Print(L);
	return 0;
}

/* 请在这里填写答案 */
LinkList Reverse(LinkList L)
{
	if (L == NULL || L->next == NULL)
		return L;

	LinkList newHead = Reverse(L->next);
	L->next->next = L;
	L->next = NULL;
	return newHead;
}