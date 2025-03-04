#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
} SqList;
void InitList(SqList &L); /*函数的实现此处不再显示*/
int SqInsert(SqList &L, ElemType e);
int main()
{
	SqList L;
	InitList(L);
	ElemType e;
	scanf("%d", &e);
	int result = SqInsert(L, e);
	if (result == 0)
	{
		printf("Insertion Error.The storage space is full!");
	}
	else if (result == 1)
	{
		printf("Insertion Success.The elements of the SequenceList L are:");
		for (int j = 0; j < L.length; j++)
		{
			printf(" %d", L.elem[j]);
		}
	}
	return 0;
}

/* 请在这里填写答案 */
int SqInsert(SqList &L, ElemType e)
{
	int pos = -1;
	if(L.length >= MAXSIZE)
	{
		return 0;
	}
	for (int i = 0;i < L.length;i++)
	{
		if (L.elem[i] > e)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)
	{
		L.elem[L.length] = e;
		L.length++;
		return 1;
	}
	else
	{
		for (int i = L.length;i > pos;i--)
		{
			L.elem[i] = L.elem[i - 1];
		}
		L.elem[pos] = e;
		L.length++;
		return 1;
	}
}