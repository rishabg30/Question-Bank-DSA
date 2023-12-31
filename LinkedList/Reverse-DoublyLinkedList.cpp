#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/reverse-a-doubly-linked-list_1116098?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
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
ListNode* reverseDLL(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	ListNode *temp = NULL;
	ListNode *curr = head;

	while (curr != NULL) {
		//We store the current's previous
		temp = curr->prev;
		//Now we change current's prev value with current's next value
		curr->prev = curr->next;
		curr->next = temp;

		curr = curr->prev;
	}
	if (temp != NULL) {
		head = temp->prev;
	}
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
	ListNode *newList = reverseDLL(head);
	printDLL(newList);
}