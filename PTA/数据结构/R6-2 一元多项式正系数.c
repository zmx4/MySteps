#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType coef; // coef表示系数
	ElemType exp;  // exp表示指数
	struct LNode *next;
} LNode, *LinkList;
LinkList Create(); /* 细节在此不表 */
int PositiveCnt(LinkList L);
int main()
{
	LinkList L, p;
	L = Create();
	printf("The number of positive coef is %d.\n", PositiveCnt(L));
	return 0;
}
/* 你的代码将被嵌在这里 */
int PositiveCnt(LinkList L)
{
	int cnt = 0;
	LNode *p = L->next;
	while (p != NULL)
	{
		if (p->coef > 0)
			cnt++;
		p = p->next;
	}
	return cnt;
}