#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/delete-middle-node_763267?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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
ListNode* deleteMiddle(ListNode* head) {
	if (head == NULL || head->next == NULL)return NULL;

	ListNode *curr = head;
	int countNodes = 0;
	while (curr != NULL) {
		countNodes++;
		curr = curr->next;
	}
	countNodes = countNodes / 2;
	int curr_count = 0;
	curr = head;
	while (curr_count < (countNodes - 1)) {
		curr = curr->next;
		curr_count++;
	}
	curr->next = curr->next->next;
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
	ListNode *updatedList = deleteMiddle(head);
	printLL(updatedList);
}