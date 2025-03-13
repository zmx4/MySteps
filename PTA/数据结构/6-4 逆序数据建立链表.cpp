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
	struct ListNode *L, *s;
	L = (struct ListNode *)malloc(sizeof(struct ListNode));
	L->next = NULL;
	
	int n;
	while(1)
	{
		scanf("%d", &n);
		if(n < 0)
			break;
		s = (struct ListNode *)malloc(sizeof(struct ListNode));
		s->data = n;
		s->next = L->next;
		L->next = s;
	}
	return L->next;
}