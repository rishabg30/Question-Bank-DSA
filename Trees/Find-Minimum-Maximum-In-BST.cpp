#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/minimum-element-in-bst_8160462?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

int maxValue(TreeNode *root) {
	if (root == NULL) {
		return INT_MIN;
	}
	TreeNode *curr = root;
	int maximum = curr->val;

	while (curr->right != NULL) {
		curr = curr->right;
		maximum = max(maximum, curr->val);
	}
	return maximum;
}
int minValue(TreeNode* root) {
	if (root == NULL) {
		return INT_MAX;
	}
	TreeNode *curr = root;
	int minimum = curr->val;

	while (curr->left != NULL) {
		curr = curr->left;
		minimum = min(minimum, curr->val);
	}
	return minimum;
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
	cout << minValue(root) << endl;
	cout << maxValue(root) << endl;
}