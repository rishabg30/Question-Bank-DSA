#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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

	printBST(root->left);
	cout << root->val << " ";
	printBST(root->right);
}
TreeNode *constructBST(vector<int>&preorder, int &i, int ub) {
	//If preOrder elements are over or at any place value of preOrder[i] > upperbound
	if (i == preorder.size() || preorder[i] > ub) {
		return NULL;
	}
	TreeNode *root = new TreeNode(preorder[i++]);
	root->left = constructBST(preorder, i, root->val);
	root->right = constructBST(preorder, i, ub);
	return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
	int i = 0;
	return constructBST(preorder, i, INT_MAX);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int>preorder = {8, 5, 1, 7, 10, 12};
	TreeNode *ans = bstFromPreorder(preorder);
	printBST(ans);
}