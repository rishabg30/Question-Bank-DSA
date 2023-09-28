#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/delete-node-in-a-bst/description/

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

TreeNode *findLastRight(TreeNode *curr) {
	while (curr->right != NULL) {
		curr = curr->right;
	}
	return curr;
}
TreeNode* helper(TreeNode *curr) {
	if (curr->left == NULL) {
		return curr->right;
	}
	else if (curr->right == NULL) {
		return curr->left;
	}
	TreeNode *rightChild = curr->right;
	TreeNode *lastRight = findLastRight(curr->left);
	lastRight->right = rightChild;
	return curr->left;
}
TreeNode* deleteNode(TreeNode* root, int key) {
	if (root == NULL) {
		return NULL;
	}
	//You have to delete the root node
	if (root->val == key) {
		return helper(root);
	}

	TreeNode *curr = root;
	while (curr != NULL) {
		if (curr->val > key) {
			if (curr->left != NULL && curr->left->val == key) {
				curr->left = helper(curr->left);
				break;
			}
			else {
				curr = curr->left;
			}
		}
		else {
			if (curr->right != NULL && curr->right->val == key) {
				curr->right = helper(curr->right);
				break;
			}
			curr = curr->right;
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
	root = deleteNode(root, 10);
	printBST(root);
}