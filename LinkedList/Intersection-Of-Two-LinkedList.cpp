#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/intersection-of-two-linked-lists/

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

ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
	if (head1 == NULL && head2 == NULL)return NULL;
	ListNode *l1 = head1;
	ListNode *l2 = head2;

	while (l1 != l2) {
		if (l1 == NULL) {
			l1 = head2;
		}
		else {
			l1 = l1->next;
		}
		if (l2 == NULL) {
			l2 = head1;
		}
		else {
			l2 = l2->next;
		}
	}
	return l1;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *head1 = new ListNode(4);
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(8);
	ListNode *n3 = new ListNode(4);
	ListNode *n4 = new ListNode(5);

	head1->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	ListNode *head2 = new ListNode(5);
	ListNode *m1 = new ListNode(6);
	ListNode *m2 = new ListNode(1);
	head2->next = m1;
	m1->next = m2;
	m2->next = n2;

	ListNode *intersectedPoint = getIntersectionNode(head1, head2);
	cout << intersectedPoint->val << endl;
}