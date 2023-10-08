#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/palindrome-linked-list/

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

ListNode *reverseLL(ListNode *head) {
	if (head == NULL || head->next == NULL)return head;

	ListNode *prev = NULL;
	ListNode *curr = head;
	while (curr != NULL) {
		ListNode *frwdnode = curr->next;
		curr->next = prev;

		prev = curr;
		curr = frwdnode;
	}
	return prev;
}
bool isPalindrome(ListNode* head) {
	if (head == NULL || head->next == NULL)return true;

	ListNode *slow = head, *fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode *ptr1 = head;

	slow = reverseLL(slow);
	while (slow->next != NULL) {
		if (ptr1->val != slow->val) {
			return false;
		}
		ptr1 = ptr1->next;
		slow = slow->next;
	}
	return true;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ListNode *head = new ListNode(3);
	ListNode *n1 = new ListNode(2);
	ListNode *n2 = new ListNode(0);
	ListNode *n3 = new ListNode(2);
	ListNode *n4 = new ListNode(3);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	cout << isPalindrome(head) << endl;
}