
typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */
void Infix(BiTree T);

int main()
{
	BiTree T = Create();
	Infix(T);
	return 0;
}
/* 你的代码将被嵌在这里 */

void Infix(BiTree T)
{
	if (!T)
		return;
	Infix(T->lchild);
	printf("%c ", T->data);
	Infix(T->rchild);
}