#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/count-nodes-of-linked-list_5884?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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
int length(ListNode *head) {
	int count = 0;
	ListNode *curr = head;
	while (curr != NULL) {
		curr = curr->next;
		count++;
	}
	return count;
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
	cout << length(n1);
}