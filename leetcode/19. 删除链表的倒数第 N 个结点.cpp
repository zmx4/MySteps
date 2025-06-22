#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode List(0, head);
        ListNode *l = &List, *r = head;
        for (int i = 0; i < n; i++)
        {
            if (r)
                r = r->next;
        }
        while (r)
        {
            r = r->next;
            l = l->next;
        }
        ListNode *temp = l->next;
        l->next = temp->next;
        delete temp;
        return List.next;
    }
};
