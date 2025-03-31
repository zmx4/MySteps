#include <stdio.h>
#include <stdlib.h>

typedef int ElemSet;
typedef struct ListNode *Position; /* 指针即结点位置 */
struct ListNode
{
	ElemSet data;  /* 存储数据 */
	Position next; /* 线性表中下一个元素的位置 */
};
typedef struct HeadNode *List;
struct HeadNode
{
	Position head; /* 单链表头指针 */
	int length;	   /* 表长 */
};

List JosephusProblem(int n, int m);

void PrintList(List list)
{ /* 顺序输出链表结点数据 */
	Position p;

	p = list->head->next; /* p指向第1个结点 */
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
int main(void)
{
	List list;
	int n, m;
	scanf("%d %d", &n, &m);
	list = JosephusProblem(n, m);
	PrintList(list);
	return 0;
}
/* 你的代码将被嵌在这里 */
List JosephusProblem(int n, int m)
{
	
}