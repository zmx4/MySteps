#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		int carry = 0;
		ListNode *p1 = l1, *p2 = l2;
		while (p1 || p2 || carry)
		{
			int sum = carry;
			if (p1)
			{
				sum += p1->val;
				p1 = p1->next;
			}
			if (p2)
			{
				sum += p2->val;
				p2 = p2->next;
			}
			carry = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
		}
		return head->next;
	}
};