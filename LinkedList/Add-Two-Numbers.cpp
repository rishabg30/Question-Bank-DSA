#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/add-two-numbers/

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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == NULL && l2 == NULL)return NULL;
	if (l1 == NULL && l2 != NULL)return l2;
	if (l1 != NULL && l2 == NULL)return l1;

	ListNode *mylist = new ListNode(-1), *d = mylist;
	int carry = 0;
	while (l1 != NULL || l2 != NULL || carry != 0) {
		int sum = 0;
		if (l1 != NULL) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			sum += l2->val;
			l2 = l2->next;
		}

		sum = sum + carry;
		ListNode *newnode = new ListNode(sum % 10);
		mylist->next = newnode;
		mylist = mylist->next;
		carry = sum / 10;
	}
	return d->next;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *head1 = new ListNode(2);
	ListNode *n1 = new ListNode(4);
	ListNode *n2 = new ListNode(3);

	head1->next = n1;
	n1->next = n2;

	ListNode *head2 = new ListNode(5);
	ListNode *m1 = new ListNode(6);
	ListNode *m2 = new ListNode(4);
	head2->next = m1;
	m1->next = m2;

	ListNode *updatedList = addTwoNumbers(head1, head2);
	printLL(updatedList);
}