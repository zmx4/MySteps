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
void reverse(LinkList L);
int main()
{
	LinkList L = Create();
	print(L);
	printf("\n");
	reverse(L);
	print(L);
	return 0;
}
LinkList Create()
{
	LinkList L, p, s;
	ElemType e;
	L = (LinkList)malloc(sizeof(LNode));
	p = L;
	scanf("%d", &e);
	while (e != -1)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = e;
		p->next = s;
		p = s;
		scanf("%d", &e);
	}
	p->next = NULL;
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
/* 请在这里填写答案 */

void reverse(LinkList L)
{
	LinkList p = L->next, q = p->next, r;
	p->next = NULL;
	while (q)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	L->next = p;
}