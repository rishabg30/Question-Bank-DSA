#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/odd-even-linked-list/

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
ListNode* oddEvenList(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode *firstList = new ListNode(-1);
	ListNode *secondList = new ListNode(-1);
	ListNode *d1 = firstList, *d2 = secondList;

	int count = 0;
	ListNode *curr = head;
	while (curr != NULL) {
		if (count == 0 || count % 2 == 0) {
			firstList->next = curr;
			firstList = firstList->next;
		}
		else {
			secondList->next = curr;
			secondList = secondList->next;
		}
		curr = curr->next;
		count++;
	}
	secondList->next = NULL;
	firstList->next = d2->next;
	return d1->next;
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
	ListNode *newList = oddEvenList(head);
	printLL(newList);
}