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
	int n;
	struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *v = p;
	scanf("%d", &n);
	while (n != -1)
	{
		struct ListNode *l = (struct ListNode *)malloc(sizeof(struct ListNode));
		l->data = n;
		l->next = NULL;
		v->next = l;
		v = l;
		scanf("%d", &n);
	}
	return p->next;
}