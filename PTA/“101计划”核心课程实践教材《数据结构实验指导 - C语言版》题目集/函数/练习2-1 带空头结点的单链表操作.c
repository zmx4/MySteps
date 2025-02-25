#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *Position; /* 指针即结点位置 */
struct ListNode
{
	ElemSet data;  /* 存储数据*/
	Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *List;
struct HeadNode
{
	Position head; /* 单链表头指针 */
	int length;	   /* 表长 */
};

void Insert(List list, int i, ElemSet x);
void Remove(List list, int i);

int main(void)
{
	int i, n, x;
	Position p;
	List list;

	list = (List)malloc(sizeof(struct HeadNode));
	list->head = (Position)malloc(sizeof(struct ListNode)); /* 创建空头结点 */
	;
	list->head->next = NULL;
	list->length = 0;
	scanf("%d: ", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		Insert(list, i, x);
	}
	scanf("%d", &i);
	if (scanf("%d", &x) != EOF)
	{
		Insert(list, i, x);
	}
	else
	{
		Remove(list, i);
	}
	printf("%d:", list->length);
	p = list->head->next;
	while (p != NULL)
	{
		printf(" %d", p->data);
		p = p->next;
	}
	return 0;
}
/* 你的代码将被嵌在这里 */
void Insert(List list, int i, ElemSet x)
{
	Position p, q;
	int j;
	p = list->head;
	j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j > i - 1)
	{
		printf("ERROR");
		return;
	}
	q = (Position)malloc(sizeof(struct ListNode));
	q->data = x;
	q->next = p->next;
	p->next = q;
	list->length++;
}
void Remove(List list, int i)
{
	Position p, q;
	int j;
	p = list->head;
	j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || j > i - 1 || p->next == NULL)
	{
		printf("ERROR");
		return;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	list->length--;
}