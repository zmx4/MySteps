
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */
void PrintNode(BiTree T);
int n; // 要打印的结点的在先序序列中的序号
int main()
{
	BiTree T = Create();
	scanf("%d", &n);
	printf("The %d-th node in preorder is: ", n);
	PrintNode(T);
	printf("\n");
	return 0;
}
/* 你的代码将被嵌在这里 */

void PrintNode(BiTree T)
{
	if (T == NULL || n <= 0)
		return;
	// 先序访问：先处理当前结点
	if (--n == 0)
	{
		printf("%c", T->data);
		return;
	}
	// 再递归左、右子树
	PrintNode(T->lchild);
	PrintNode(T->rchild);
}
