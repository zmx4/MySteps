#include <stdio.h>
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree Create(); /* 细节在此不表 */
int Infix_num(BiTree T);

int main()
{
    BiTree T = Create();
    printf("\n%d", Infix_num(T));
    return 0;
}
/* 你的代码将被嵌在这里 */
int Infix_num(BiTree T)
{
    if (T == NULL)
        return 0;
    if (T->lchild == NULL && T->rchild == NULL)
        return 0;
    else
    {
        int x = 0;
        int left = Infix_num(T->lchild);
        if(T->data == '+'||T->data == '-'||T->data == '*'||T->data == '/')
        {
            x++;
            printf("%c ", T->data);
        }
        int right = Infix_num(T->rchild);
        return left + right + x;
    }
}