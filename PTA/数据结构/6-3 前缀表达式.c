
typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */
void Prefix(BiTree T);

int main()
{
	BiTree T = Create();
	Prefix(T);
	return 0;
}
/* 你的代码将被嵌在这里 */

void Prefix(BiTree T)
{
	if(!T)
		return;
	printf("%c ", T->data);
	Prefix(T->lchild);
	Prefix(T->rchild);
}