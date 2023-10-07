#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/middle-of-the-linked-list/

class ListNode {
public:
	int val;
	ListNode *next;

	ListNode() {

	}
	ListNode(int val) {
		this->val = val;
		next = NULL;
	}
};

ListNode* middleNode(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;

	ListNode *slow = head, *fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *head = new ListNode(1);
	ListNode *n1 = new ListNode(2);
	ListNode *n2 = new ListNode(3);
	ListNode *n3 = new ListNode(4);
	ListNode *n4 = new ListNode(5);
	ListNode *n5 = new ListNode(6);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	ListNode *middle = middleNode(head);
	cout << middle->val << endl;
}