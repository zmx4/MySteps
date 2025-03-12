#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int data;
	struct ListNode *next;
};

struct ListNode *createlist();

int main()
{
	struct ListNode *p, *head = NULL;

	head = createlist();
	for (p = head; p != NULL; p = p->next)
		printf("%d ", p->data);
	printf("\n");

	return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist()
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(ListNode));
	head->next = NULL;
	struct ListNode *p = head;
	int n;
	while(scanf("%d", &n) != EOF)
	{
		ListNode *node = (struct ListNode *)malloc(sizeof(ListNode));
		node->data = n;
		node->next = NULL;
		p->next = node;
		p = node;
	}
	struct ListNode *q = head;
	head = head->next;
	free(q);
	return head;
}