
typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */
void Suffix(BiTree T);

int main()
{
	BiTree T = Create();
	Suffix(T);
	return 0;
}
/* 你的代码将被嵌在这里 */

void Suffix(BiTree T)
{
	if(!T)
		return;
	Suffix(T->lchild), Suffix(T->rchild);
	printf(" %c", T->data);
}