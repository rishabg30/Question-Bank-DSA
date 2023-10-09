#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/add-one-to-a-number-represented-as-linked-list_920557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

ListNode *reverseList(ListNode *head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode *prev = NULL;
	ListNode *curr = head;

	while (curr != NULL) {
		ListNode *frwdnode = curr->next;
		curr->next = prev;

		prev = curr;
		curr = frwdnode;
	}
	return prev;
}
ListNode *addOne(ListNode *head) {
	head = reverseList(head);

	ListNode *curr = head;
	int first_element = curr->val;
	first_element += 1;

	curr->val = (first_element) % 10;
	int carry = (first_element) / 10;
	curr = curr->next;

	while (curr != NULL) {
		int new_value = ((curr->val) + carry);
		curr->val = (new_value) % 10;
		carry = new_value / 10;
		curr = curr->next;
	}

	if (carry != 0) {
		ListNode *newnode = new ListNode(carry);
		newnode->next = head;
		return newnode;
	}
	return reverseList(head);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *head = new ListNode(9);
	ListNode *n1 = new ListNode(9);
	ListNode *n2 = new ListNode(9);

	head->next = n1;
	n1->next = n2;

	ListNode *updatedList = addOne(head);
	printLL(updatedList);
}