#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/recover-binary-search-tree/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

TreeNode *first;
TreeNode *prev;
TreeNode *middle;
TreeNode *last;
void inOrderTraversal(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	inOrderTraversal(root->left);
	if (prev != NULL && (root->val < prev->val)) {

		//Check whether it's the first violation or the second violation
		if (first == NULL) {
			first = prev;
			middle = root;
		}
		//If it's a second violation
		else {
			last = root;
		}
	}
	prev = root;
	inOrderTraversal(root->right);
}
void recoverTree(TreeNode* root) {
	first = middle = last = NULL;
	prev = new TreeNode(INT_MIN);
	inOrderTraversal(root);
	if (first != NULL && last != NULL) {
		//Both violations happened
		swap(first->val, last->val);
	}
	else if (first != NULL  && middle != NULL) {
		//Only first violation
		swap(first->val, middle->val);
	}
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
	recoverTree(root);
}