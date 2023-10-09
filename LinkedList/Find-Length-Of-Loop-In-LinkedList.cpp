#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/find-length-of-loop_8160455?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

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

int lengthOfLoop(ListNode *head) {
	if (head == NULL)return 0;

	ListNode *slow = head, *fast = head;
	bool hasCycle = false;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			hasCycle = true;
			break;
		}
	}
	//No cycle formed is hasCycle == false
	if (hasCycle == false)return 0;

	int count = 1;
	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	ListNode *startPoint_Of_Cycle = slow;
	fast = fast->next;
	//This is the point where they will meet i.e start point of the loop
	while (fast != startPoint_Of_Cycle) {
		count++;
		fast = fast->next;
	}
	return count;
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
	ListNode *n3 = new ListNode(4);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n1;

	cout << lengthOfLoop(head);
}