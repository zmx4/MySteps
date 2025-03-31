#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int data;
	struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven(struct ListNode *head);
void printlist(struct ListNode *head)
{
	struct ListNode *p = head;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	struct ListNode *head;

	head = createlist();
	head = deleteeven(head);
	printlist(head);

	return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist()
{
	struct ListNode *head = NULL, *p = NULL, *q = NULL;
	int n;
	while(scanf("%d", &n) && n != -1)
	{
		p = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->data = n;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			q->next = p;
		q = p;
	}
	return head;
}
struct ListNode *deleteeven(struct ListNode *head)
{
	struct ListNode *p = head, *q = NULL;
	while (p && p->data % 2 == 0)
	{
		q = p;
		p = p->next;
		free(q);
	}
	head = p;
	while (p && p->next)
	{
		if (p->next->data % 2 == 0)
		{
			q = p->next;
			p->next = q->next;
			free(q);
		}
		else
			p = p->next;
	}
	return head;
}