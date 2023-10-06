#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/delete-last-node-of-a-doubly-linked-list_8160469?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
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
ListNode* deleteLastNode(ListNode *head) {
	if (head->next == NULL) {
		head = NULL;
		return head;
	}

	ListNode *curr = head;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}
	curr->next = NULL;
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
	head = deleteLastNode(head);
	printDLL(head);
}