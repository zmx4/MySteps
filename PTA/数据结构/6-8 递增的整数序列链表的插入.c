#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode List;

List Read();		/* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Insert(List L, ElementType X);

int main()
{
	List L;
	ElementType X;
	L = Read();
	scanf("%d", &X);
	L = Insert(L, X);
	Print(L);
	return 0;
}

/* 你的代码将被嵌在这里 */
List Insert(List L, ElementType X)
{
	List p = L;
	while (p->Next != NULL && p->Next->Data <= X)
	{
		p = p->Next;
	}
	List n = (List)malloc(sizeof(struct Node));
	
	n->Next = p->Next;
	p->Next = n;
	n->Data = X;
	return L;
}