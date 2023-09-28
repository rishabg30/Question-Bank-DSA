#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/validate-binary-search-tree/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

bool isValid(TreeNode *node, long long minValue, long long maxValue) {
	if (node == NULL) {
		return true;
	}
	if (node->val >= maxValue || node->val <= minValue) {
		return false;
	}
	return isValid(node->left, minValue, node->val)
	       && isValid(node->right, node->val, maxValue);
}
bool isValidBST(TreeNode* root) {
	if (root == NULL) {
		return true;
	}
	return isValid(root, -1e18, 1e18);
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
	cout << isValidBST(root) << endl;
}