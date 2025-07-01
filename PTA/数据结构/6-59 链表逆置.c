#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse(struct ListNode *head);
void printlist(struct ListNode *head)
{
    struct ListNode *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = reverse(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *stack[1000];
    int tt = 0;
    while (head)
    {
        stack[tt] = head;
        tt++;
        head = head->next;
    }
    struct ListNode p = (struct ListNode){0, NULL};
    struct ListNode *tail = &p;
    while (tt > 0)
    {
        tt--;
        tail->next = stack[tt];
        tail = tail->next;
        tail->next = NULL; // 确保最后一个节点的 next 指向 NULL
    }
    return p.next; // 返回新链表的头节点
}