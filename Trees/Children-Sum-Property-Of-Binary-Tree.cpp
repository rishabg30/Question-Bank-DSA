#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};
void printTree(TreeNode *root) {
	if (root == NULL)return;
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}

void childrenSumProperty(TreeNode *root) {
	if (root == NULL)return;
	int childsum = 0;
	if (root->left) {
		childsum += root->left->val;
	}
	if (root->right) {
		childsum += root->right->val;
	}

	if (childsum >= root->val) {
		root->val = childsum;
	}
	else {
		if (root->left) {
			root->left->val = root->val;
		}
		if (root->right) {
			root->right->val = root->val;
		}
	}

	childrenSumProperty(root->left);
	childrenSumProperty(root->right);

	//Coming back from recursion
	int total = 0;
	if (root->left) {
		total += root->left->val;
	}
	if (root->right) {
		total += root->right->val;
	}

	//Check if node is not a leaf node
	if (root->left || root->right) {
		root->val = total;
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
	childrenSumProperty(root);
	printTree(root);
}