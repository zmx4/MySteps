#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

LinkList Create();
void print(LinkList L);

int main()
{
	LinkList L = Create();
	print(L);
	return 0;
}
LinkList Create()
{
	LinkList L, p, s;
	ElemType e;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;

	p = L;
	
	scanf("%d", &e);
	while (e != -1)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = e;
		s->next = NULL;

		p->next = s;

		p = s;
		scanf("%d", &e);
	}

	return L;
}
void print(LinkList L)
{
	LinkList p;
	p = L->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}