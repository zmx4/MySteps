#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int64_t ElementType;
typedef struct Node *PtrToNode;
struct Node
{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode List;

List createList(int n)
{
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	List tail = L;
	for (int i = 0; i < n; i++)
	{
		List newNode = (List)malloc(sizeof(struct Node));
		scanf("%lld", &newNode->Data);
		newNode->Next = NULL;
		tail->Next = newNode;
		tail = newNode;
	}
	return L;
}
List merge(List a, List b)
{
	List dummy = (List)malloc(sizeof(struct Node));
	dummy->Next = NULL;
	List tail = dummy;
	List pa = a->Next, pb = b->Next;
	while (pa && pb)
	{
		if (pa->Data < pb->Data)
		{
			tail->Next = pa;
			pa = pa->Next;
		}
		else
		{
			tail->Next = pb;
			pb = pb->Next;
		}
		tail = tail->Next;
	}
	if (pa)
		tail->Next = pa;
	else
		tail->Next = pb;
	List mergedHead = dummy->Next;
	free(dummy);
	return mergedHead;
}

void printList(List L)
{
	List p = L;
	while (p)
	{
		printf("%lld ", p->Data);
		p = p->Next;
	}
	printf("\n");
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	List a = createList(n);
	List b = createList(m);
	List merged = merge(a, b);
	printList(merged);
	return 0;
}