#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/rotate-list/description/

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

int findLength(ListNode *head) {
	if (head == NULL)return 0;
	int count = 0;
	ListNode *curr = head;

	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}
ListNode * rotateRight(ListNode* head, int k) {
	//Edge cases
	if (head == NULL || head->next == NULL)return head;
	int sizeOfLL = findLength(head);
	if (k == 0 || k == sizeOfLL || k % sizeOfLL == 0)return head;

	k = k % sizeOfLL;
	ListNode *curr = head;
	k = sizeOfLL - k;

	int count = 1;
	while (count < k) {
		curr = curr->next;
		count++;
	}
	ListNode *frwdnode = curr->next;
	curr->next = NULL;

	ListNode *curr2 = frwdnode;
	while (curr2->next != NULL) {
		curr2 = curr2->next;
	}
	curr2->next = head;
	return frwdnode;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *head = new ListNode(1);
	ListNode *n1 = new ListNode(2);
	ListNode *n2 = new ListNode(3);
	ListNode *n3 = new ListNode(4);
	ListNode *n4 = new ListNode(5);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	int k; cin >> k;
	ListNode *updatedList = rotateRight(head, k);
	printLL(updatedList);
}