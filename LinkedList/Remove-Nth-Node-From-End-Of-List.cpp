#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

void printLL(ListNode *head) {
	if (head == NULL) {
		return;
	}
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == NULL || (head->next == NULL && n == 1)) {
		return NULL;
	}
	ListNode *slow = head, *fast = head;
	while (n--) {
		fast = fast->next;
		if (fast == NULL) {
			return head->next;
		}
	}
	while (fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;
	return head;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *head = new ListNode(3);
	ListNode *n1 = new ListNode(2);
	ListNode *n2 = new ListNode(5);
	ListNode *n3 = new ListNode(2);
	ListNode *n4 = new ListNode(3);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	int n; cin >> n;
	ListNode *updatedList = removeNthFromEnd(head, n);
	printLL(updatedList);
}