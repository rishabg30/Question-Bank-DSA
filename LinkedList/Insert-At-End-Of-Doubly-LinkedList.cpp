#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/insert-at-end-of-doubly-linked-list_8160464?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class ListNode {
public:
	int val;
	ListNode *next;
	ListNode *prev;

	ListNode() {

	}
	ListNode(int val) {
		this->val = val;
		next = NULL;
		prev = NULL;
	}
};
void printDLL(ListNode *head) {
	if (head == NULL) {
		return;
	}
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
}
ListNode* insertAtTail(ListNode *head, int k) {
	if (head == NULL) {
		ListNode *node = new ListNode(k);
		return node;
	}
	ListNode *curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	ListNode *node = new ListNode(k);
	curr->next = node;
	node->prev = curr;
	return head;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *head = new ListNode(4);
	ListNode *n1 = new ListNode(10);
	ListNode *n2 = new ListNode(3);
	ListNode *n3 = new ListNode(5);

	head->next = n1, n1->prev = head;
	n1->next = n2, n2->prev = n1;
	n2->next = n3, n3->prev = n2;

	head = insertAtTail(head, 20);
	printDLL(head);
}