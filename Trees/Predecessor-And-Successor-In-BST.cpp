#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

void findPredecessor(TreeNode *root, int &predecessor, int key) {
	if (root == NULL) {
		return;
	}
	TreeNode *curr = root;
	while (curr != NULL) {
		if (curr->val >= key) {
			curr = curr->left;
		}
		else {
			predecessor = curr->val;
			curr = curr->right;
		}
	}
}
void findSuccessor(TreeNode *root, int &successor, int key) {
	if (root == NULL) {
		return;
	}
	TreeNode *curr = root;
	while (curr != NULL) {
		if (curr->val > key) {
			successor = curr->val;
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key) {
	int predecessor = -1, successor = -1;
	findPredecessor(root, predecessor, key);
	findSuccessor(root, successor, key);
	return make_pair(predecessor, successor);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	TreeNode *root = new TreeNode(8);
	TreeNode *n1 = new TreeNode(3);
	TreeNode *n2 = new TreeNode(10);
	root->left = n1, root->right = n2;

	TreeNode *n3 = new TreeNode(1);
	TreeNode *n4 = new TreeNode(6);
	TreeNode *n5 = new TreeNode(14);
	n1->left = n3, n1->right = n4;
	n2->right = n5;

	TreeNode *n6 = new TreeNode(4);
	TreeNode *n7 = new TreeNode(7);
	TreeNode *n8 = new TreeNode(13);
	n4->left = n6, n4->right = n7;
	n5->left = n8;
	pair<int, int>myPair = predecessorSuccessor(root, 1);
	cout << myPair.first << " " << myPair.second << endl;
}