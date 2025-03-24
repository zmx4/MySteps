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
	struct ListNode *p = NULL;
	// struct ListNode *pp = p;
	// p->next = NULL;
	while (1)
	{
		scanf("%d", &n);
		if (n == -1)
			break;
		struct ListNode *s = (struct ListNode *)malloc(sizeof(struct ListNode));
		s->data = n;
		s->next = p;
		p = s;
	}
	return p;
}