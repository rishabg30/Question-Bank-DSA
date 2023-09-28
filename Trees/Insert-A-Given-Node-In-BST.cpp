#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

void printBST(TreeNode *root) {
	if (root == NULL)return;
	cout << root->val << " ";
	printBST(root->left);
	printBST(root->right);
}
TreeNode* insertIntoBST(TreeNode* root, int val) {
	if (root == NULL) {
		return new TreeNode(val);
	}
	TreeNode *curr = root;

	while (true) {
		if (curr->val <= val) {
			//Move to the right side
			if (curr->right != NULL) {
				curr = curr->right;
			}
			else {
				curr->right = new TreeNode(val);
				break;
			}
		}
		else {
			//Move to the left side
			if (curr->left != NULL) {
				curr = curr->left;
			}
			else {
				curr->left = new TreeNode(val);
				break;
			}
		}
	}
	return root;
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
	root = insertIntoBST(root, 11);
	printBST(root);
}