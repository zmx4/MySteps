#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
} SqList;
void InitList(SqList &L); /*细节在此不表*/
void PrintLIst(SqList L);
void Replace(SqList &L, int e);
int main()
{
	SqList L;
	int e;
	InitList(L);
	scanf("%d", &e);
	Replace(L, e);
	PrintLIst(L);
	return 0;
}
void PrintLIst(SqList L)
{
	for (int i = 0; i < L.length; i++)
		printf("%d ", L.elem[i]);
}

/* 请在这里填写答案 */
void Replace(SqList &L, int e)
{
	for(int i  = 0; i < L.length; i++)
	{
		if(L.elem[i] > 0)
		{
			L.elem[i] = e;
		}
	}
}