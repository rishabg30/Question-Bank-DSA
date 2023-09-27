#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/search-in-a-binary-search-tree/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

TreeNode* searchBST(TreeNode* root, int val) {
	if (root == NULL) {
		return root;
	}

	TreeNode *curr = root;
	while (curr != NULL) {
		if (curr->val == val) {
			return curr;
		}
		else if (curr->val > val) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}
	}
	return curr;
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
	TreeNode *searchNode = searchBST(root, 10);
}