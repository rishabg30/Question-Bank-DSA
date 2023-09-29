#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/largest-bst/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

class BST {
public:
	int maxNodeValue, minNodeValue, size;
	BST() {

	}
	BST(int minNodeValue, int maxNodeValue, int size) {
		this->minNodeValue = minNodeValue;
		this->maxNodeValue = maxNodeValue;
		this->size = size;
	}
};
BST myLargestBST(TreeNode *root) {
	if (root == NULL) {
		return BST(INT_MAX, INT_MIN, 0);
	}
	BST myAns;
	BST left = myLargestBST(root->left);
	BST right = myLargestBST(root->right);
	if ((left.maxNodeValue < root->val) && (root->val < right.minNodeValue)) {
		//It is a BST
		myAns.minNodeValue = min(left.minNodeValue, root->val);
		myAns.maxNodeValue = max(right.maxNodeValue, root->val);
		myAns.size = left.size + right.size + 1;
	}
	else {
		myAns.minNodeValue = -1e9;
		myAns.maxNodeValue = 1e9;
		myAns.size = max(left.size, right.size);
	}
	return myAns;
}
int largestBst(TreeNode *root) {
	BST myAns = myLargestBST(root);
	return myAns.size;
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
	cout << largestBst(root) << endl;
}