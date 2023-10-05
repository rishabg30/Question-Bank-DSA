#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/delete-node-in-a-linked-list/

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
void deleteNode(ListNode* node) {

}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	deleteNode(n1);
	printLL(n1);
}