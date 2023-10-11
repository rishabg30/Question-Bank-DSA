#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/flatten-a-linked-list_1112655?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

TreeNode* flattenLinkedList(TreeNode* head) {

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

	ListNode *updatedList = flattenLinkedList(head);
	printLL(updatedList);
}