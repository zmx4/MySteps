#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        int len = 0;
        ListNode *tail = head;
        while (tail)
        {
            len++;
            if (tail->next == nullptr)
                break;
            tail = tail->next;
        }
        if (len == 0 || len == 1 || k % len == 0)
            return head;
        int idx = len - k % len;
        ListNode *l = head;
        for (int i = 0; i < idx - 1; i++)
        {
            l = l->next;
        }
        ListNode *newHead = l->next;
        l->next = nullptr;
        tail->next = head;
        return newHead;
    }
};