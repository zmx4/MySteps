#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

void PrintNode(BiTree T, int n);
int main()
{
	BiTree T = Create();
	int n;
	scanf("%d", &n);
	printf("The %d-th node in levelorder is: ", n);
	PrintNode(T, n);
	printf("\n");
	return 0;
}
/* 你的代码将被嵌在这里 */
void PrintNode(BiTree T,int n)
{
	if(!T)
		return;
	int hh = 0,tt = 0;
	BiTree q[1000];	
	q[tt++] = T;
	int cnt = 0;
	while(hh < tt)
	{
		BiTree p = q[hh++];
		cnt++;
		if(cnt == n)printf("%c", p->data);
		if(p->lchild)q[tt++] = p->lchild;
		if(p->rchild)q[tt++] = p->rchild;
	}	
}