#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/linked-list-cycle-ii/

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

ListNode *detectCycle(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return NULL;
	}
	ListNode *slow = head, *fast = head;

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			slow = head;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return NULL;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *head = new ListNode(3);
	ListNode *n1 = new ListNode(2);
	ListNode *n2 = new ListNode(0);
	ListNode *n3 = new ListNode(4);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n1;
	ListNode *startPoint = detectCycle(head);
	cout << startPoint->val << endl;
}