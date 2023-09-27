#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

/*
M-1 Using Recursion

void bT_To_LL(TreeNode* root, TreeNode* &prev) {
	if (root == NULL)return;
	bT_To_LL(root->right, prev);
	bT_To_LL(root->left, prev);

	root->right = prev;
	root->left = NULL;
	prev = root;
}
void flatten(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	TreeNode *prev = NULL;
	bT_To_LL(root, prev);
}
*/



TreeNode *getRigthMostNode(TreeNode *node, TreeNode *curr) {
	while (node->right != NULL && node->right != curr) {
		node = node->right;
	}
	return node;
}
void getPreOrder_MorrisTraversal(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	vector<int>ans;
	TreeNode *curr = root;

	while (curr != NULL) {
		TreeNode *left = curr->left;
		if (left != NULL) {
			TreeNode *rightMostNode = getRigthMostNode(left, curr);
			rightMostNode->right = curr->right;
			curr->right = curr->left;
			curr->left = NULL;
		}
		curr = curr->right;
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	TreeNode *root = new TreeNode(1);
	TreeNode *n1 = new TreeNode(2);
	TreeNode *n2 = new TreeNode(3);
	root->left = n1, root->right = n2;

	TreeNode *n3 = new TreeNode(4);
	TreeNode *n4 = new TreeNode(5);
	TreeNode *n5 = new TreeNode(7);
	TreeNode *n6 = new TreeNode(8);
	n1->left = n3, n1->right = n4;
	n2->left = n5, n2->right = n6;

	TreeNode *n7 = new TreeNode(6);
	TreeNode *n8 = new TreeNode(9);
	TreeNode *n9 = new TreeNode(10);
	n4->left = n7;
	n6->left = n8, n6->right = n9;
	getPreOrder_MorrisTraversal(root);
}