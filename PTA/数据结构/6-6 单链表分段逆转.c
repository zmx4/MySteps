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

List ReadInput()
{ /* 读输入，创建带头结点的单链表 */
	int n, i;
	List list;
	Position tail, new_node;

	list = (List)malloc(sizeof(struct HeadNode));
	list->head = (Position)malloc(sizeof(struct ListNode)); /* 创建空头结点 */
	scanf("%d", &n);
	list->length = n;
	tail = list->head; /* 初始化尾指针 */
	for (i = 0; i < n; i++)
	{
		new_node = (Position)malloc(sizeof(struct ListNode));
		scanf("%d", &new_node->data);
		new_node->next = NULL;
		tail->next = new_node; /* 插入表尾 */
		tail = new_node;
	}
	return list;
}

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

void K_Reverse(List list, int k);

int main(void)
{
	List list;
	int k;

	list = ReadInput();
	scanf("%d", &k);
	K_Reverse(list, k);
	PrintList(list);

	return 0;
}
/* 你的代码将被嵌在这里 */
void K_Reverse(List list, int k)
{
	if (k <= 1)
		return;
	Position h = list->head;
	int len = list->length;
	
	Position p = h;
	while(len > k)
	{
		Position cur = p -> next;
		for (int i = 1; i < k;i++)
		{
			Position r = cur->next;
			cur->next = r->next;
			r->next = p->next;
			p->next = r;
		}
		p = cur;
		len -= k;
	}
}