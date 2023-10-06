#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/search-in-a-linked-list_975381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int searchInLinkedList(ListNode *head, int k) {
	ListNode *curr = head;
	while (curr != NULL) {
		if (curr->val == k) {
			return 1;
		}
		curr = curr->next;
	}
	return 0;
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
	cout << searchInLinkedList(n1, 3) << endl;
}