#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/sort-list/

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
ListNode *findMiddleNode(ListNode *head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode *slow = head, *fast = head;

	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if (l1 == NULL && l2 == NULL)return NULL;
	if (l1 == NULL && l2 != NULL)return l2;
	if (l1 != NULL && l2 == NULL)return l1;

	ListNode *mergedList = new ListNode(-1);
	ListNode *d = mergedList;

	while (l1 != NULL && l2 != NULL) {
		if (l1->val <= l2->val) {
			mergedList->next = l1;
			l1 = l1->next;
		}
		else {
			mergedList->next = l2;
			l2 = l2->next;
		}
		mergedList = mergedList->next;
	}

	if (l1 != NULL) {
		mergedList->next = l1;
	}
	if (l2 != NULL) {
		mergedList->next = l2;
	}
	return d->next;
}
ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;

	ListNode *middleNode = findMiddleNode(head);
	ListNode *newHead = middleNode->next;
	middleNode->next = NULL;
	return mergeTwoLists(sortList(head), sortList(newHead));
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
	ListNode *updatedList = sortList(head);
	printLL(updatedList);
}