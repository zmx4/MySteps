
#include <stdio.h>
#include <stdlib.h>
typedef char ElementType;
typedef struct BiTNode
{
	ElementType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
	int level;
} BiTNode, *BiTree;
BiTree Create(); /*细节在此不表*/
int PrintAncestors(BiTree T, char ch);
int main()
{
	BiTree T = Create();
	char ch;
	scanf("\n%c", &ch);
	int res = PrintAncestors(T, ch);
	if (!res)
		printf("%c not exist in this tree!", ch);
	return 0;
}
/* 你的代码将被嵌在这里 */

int PrintAncestors(BiTree T, char ch)
{
	if (!T)
		return 0;
	if (T->data == ch)
	{
		//printf("%c ", T->data);
		return 1;
	}
	if (PrintAncestors(T->lchild, ch) || PrintAncestors(T->rchild, ch))
	{
		printf("%c ", T->data);
		return 1;
	}
	return 0;
}