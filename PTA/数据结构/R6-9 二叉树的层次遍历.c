#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */

void Levelorder(BiTree T);

int main()
{
	BiTree T = Create();
	printf("Levelorder:");
	Levelorder(T);
	printf("\n");
	return 0;
}
/* 你的代码将被嵌在这里 */

void Levelorder(BiTree T)
{
    if (!T)
        return;

    // 创建一个队列用于层次遍历
    BiTree queue[100]; // 假设树的节点数不超过100
    int front = 0, rear = 0;

    // 根节点入队
    queue[rear++] = T;

    while (front < rear)
    {
        // 出队
        BiTree current = queue[front++];

        // 访问当前节点
        printf(" %c", current->data);

        // 左孩子入队
        if (current->lchild)
            queue[rear++] = current->lchild;

        // 右孩子入队
        if (current->rchild)
            queue[rear++] = current->rchild;
    }
}