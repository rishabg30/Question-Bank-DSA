#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/diameter-of-binary-tree/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

int heightBT(TreeNode *root, int &maxDiameter) {
	if (root == NULL) {
		return 0;
	}
	int leftHeight = heightBT(root->left, maxDiameter);
	int rightHeight = heightBT(root->right, maxDiameter);
	maxDiameter = max(maxDiameter, leftHeight + rightHeight);
	return 1 + max(leftHeight, rightHeight);
}
int diameterOfBinaryTree(TreeNode *root) {
	if (root == NULL) {
		return 0;
	}
	int maxDiameter = 0;
	heightBT(root, maxDiameter);
	return maxDiameter;
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
	cout << diameterOfBinaryTree(root) << endl;
}