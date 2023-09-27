#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

void postOrder_Traversal(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	postOrder_Traversal(root->left);
	postOrder_Traversal(root->right);
	cout << root->val << " ";
}

TreeNode *constructTree(vector<int>&postorder, int postStart, int postEnd, vector<int>&inorder, int inStart,
                        int inEnd, map<int, int>&inOrder_map) {
	if (postStart > postEnd || inStart > inEnd) {
		return NULL;
	}

	TreeNode *root = new TreeNode(postorder[postEnd]);
	int index_of_root = inOrder_map[root->val];
	int numbers_on_left = index_of_root - inStart;

	root->left = constructTree(postorder, postStart , postStart + numbers_on_left - 1, inorder, inStart, index_of_root - 1,
	                           inOrder_map);
	root->right = constructTree(postorder, postStart + numbers_on_left, postEnd - 1, inorder, index_of_root + 1, inEnd,
	                            inOrder_map);
	return root;
}
TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) {
	map<int, int>inOrder_map;
	for (int i = 0; i < inorder.size(); i++) {
		inOrder_map.insert({inorder[i], i});
	}
	TreeNode *root = constructTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inOrder_map);
	return root;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int>postorder = {9, 15, 7, 20, 3};
	vector<int>inorder = {9, 3, 15, 20, 7};
	TreeNode *myTree = buildTree(inorder, postorder);
	postOrder_Traversal(myTree);
}