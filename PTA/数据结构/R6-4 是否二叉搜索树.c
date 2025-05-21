#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	false,
	true
} bool;
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree BuildTree(); /* 由裁判实现，细节不表 */
bool IsBST(BinTree T);

int main()
{
	BinTree T;

	T = BuildTree();
	if (IsBST(T))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
/* 你的代码将被嵌在这里 */
bool _checkBST(BinTree T, int minv, int maxv)
{
	if (T == NULL)
		return true;
	if (T->Data <= minv || T->Data >= maxv)
		return false;
	return _checkBST(T->Left, minv, T->Data) && _checkBST(T->Right, T->Data, maxv);
}

bool IsBST(BinTree T)
{
	return _checkBST(T, INT_MIN, INT_MAX);
}