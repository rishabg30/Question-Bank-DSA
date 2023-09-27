#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

void preOrder_Traversal(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	cout << root->val << " ";
	preOrder_Traversal(root->left);
	preOrder_Traversal(root->right);
}

TreeNode *constructTree(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart,
                        int inEnd, map<int, int>&inOrder_map) {
	//Base Case
	if (preStart > preEnd || inStart > inEnd) {
		return NULL;
	}

	TreeNode *root = new TreeNode(preorder[preStart]);
	int index_of_root = inOrder_map[root->val];
	int numbers_on_left = index_of_root - inStart;

	root->left = constructTree(preorder, preStart + 1, preStart + numbers_on_left, inorder, inStart,
	                           index_of_root - 1, inOrder_map);
	root->right = constructTree(preorder, preStart + numbers_on_left + 1, preEnd, inorder, index_of_root + 1,
	                            inEnd, inOrder_map);
	return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	map<int, int>inOrder_map;
	for (int i = 0; i < inorder.size(); i++) {
		inOrder_map.insert({inorder[i], i});
	}
	TreeNode *root = constructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inOrder_map);
	return root;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>preorder = {3, 9, 20, 15, 7};
	vector<int>inorder = {9, 3, 15, 20, 7};
	TreeNode *myTree = buildTree(preorder, inorder);
	preOrder_Traversal(myTree);
}