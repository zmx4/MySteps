#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

LinkList Create(); /* 细节在此不表 */
void print(LinkList L);
int delete_link(LinkList L, int i);

int main()
{

	LinkList L = Create();
	int position;
	int flag;
	scanf("%d", &position);
	flag = delete_link(L, position);
	if (flag)
	{
		print(L);
	}
	else
	{
		printf("Wrong Position for Deletion");
	}
	return 0;
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
int delete_link(LinkList L, int i)
{
	LinkList p = L->next;
	if (!p)
		return 0;
	int cnt = 1;
	if(i == 1)
	{
		L->next = p->next;
		free(p);
		return 1;
	}
	while (p)
	{
		if (cnt == i - 1)
		{
			LinkList q = p->next;
			if (!q)
				return 0;
			p->next = q->next;
			free(q);
			return 1;
		}
		p = p->next;
		cnt++;
	}
	return 0;
}