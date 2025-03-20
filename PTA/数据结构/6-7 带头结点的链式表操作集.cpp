#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum
{
	false,
	true
} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);

int main()
{
	List L;
	ElementType X;
	Position P;
	int N;
	bool flag;

	L = MakeEmpty();
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &X);
		flag = Insert(L, X, L->Next);
		if (flag == false)
			printf("Wrong Answer\n");
	}
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else
		{
			flag = Delete(L, P);
			printf("%d is found and deleted.\n", X);
			if (flag == false)
				printf("Wrong Answer.\n");
		}
	}
	flag = Insert(L, X, NULL);
	if (flag == false)
		printf("Wrong Answer\n");
	else
		printf("%d is inserted as the last element.\n", X);
	P = (Position)malloc(sizeof(struct LNode));
	flag = Insert(L, X, P);
	if (flag == true)
		printf("Wrong Answer\n");
	flag = Delete(L, P);
	if (flag == true)
		printf("Wrong Answer\n");
	for (P = L->Next; P; P = P->Next)
		printf("%d ", P->Data);
	return 0;
}
/* 你的代码将被嵌在这里 */
List MakeEmpty()
{
	List L = (Position)malloc(sizeof(struct LNode));
	L->Next = NULL;
	return L;
}
Position Find(List L, ElementType X)
{
	Position p = L->Next;
	while (p != NULL && p->Data != X)
		p = p->Next;
	return p;
}
bool Insert(List L, ElementType X, Position P)
{
	int cnt = 0;
	List p = L, q;
	while (p->Next != NULL && p->Next != P)
	{
		p = p->Next;
	}
	if (p->Next != P && P != NULL)
	{
		puts("Wrong Position for Insertion");
		return false;
	}
	List n = (Position)malloc(sizeof(struct LNode));
	n->Data = X;
	n->Next = p->Next;
	p->Next = n;
	return true;
}
bool Delete(List L, Position P)
{
	List p = L;
	while (p->Next != NULL && p->Next != P)
	{
		p = p->Next;
	}
	if (p->Next != P)
	{
		puts("Wrong Position for Deletion");
		return false;
	}
	p->Next = P->Next;
	free(P);
	return true;
}