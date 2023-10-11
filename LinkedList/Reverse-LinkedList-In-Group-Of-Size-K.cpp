#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/reverse-nodes-in-k-group/
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
void printLL(ListNode *head) {
	if (head == NULL) {
		return;
	}
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
}

ListNode *th = NULL, *tt = NULL;
void addFirst(ListNode *node) {
	if (th == NULL) {
		th = tt = node;
	}
	else {
		node->next = th;
		th = node;
	}
}
int findLength(ListNode *head) {
	if (head == NULL) {
		return 0;
	}

	ListNode *curr = head;
	int count = 0;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}
ListNode * reverseKGroup(ListNode* head, int k) {
	if (head == NULL || head->next == NULL || k <= 1) {
		return head;
	}
	int length = findLength(head);
	ListNode *ah = NULL, *at = NULL, *curr = head;
	while (length >= k) {
		int temp = k;
		while (temp > 0) {
			ListNode *frwdnode = curr->next;
			curr->next = NULL;
			addFirst(curr);
			curr = frwdnode;
			temp--;
		}
		if (ah == NULL) {
			ah = th;
			at = tt;
		}
		else {
			at->next = th;
			at = tt;
		}
		th = tt = NULL;
		length -= k;
	}
	at->next = curr;
	return ah;
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
	ListNode *updatedList = reverseKGroup(head, 2);
	printLL(updatedList);
}