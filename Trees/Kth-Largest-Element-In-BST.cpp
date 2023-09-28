#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

void inOrder_traversal(TreeNode *root, int &totalNodes) {
	if (root == NULL) {
		return;
	}
	inOrder_traversal(root->left, totalNodes);
	totalNodes++;
	inOrder_traversal(root->right, totalNodes);
}

void kthSmallest(TreeNode *root, int &k, int &ans) {
	if (root == NULL) {
		return;
	}
	kthSmallest(root->left, k, ans);
	k--;
	if (k == 0) {
		ans = root->val;
		return;
	}
	kthSmallest(root->right, k, ans);
}
int kthLargest(TreeNode* root, int k) {
	int ans = 0, totalNodes = 0, original_k = k;
	inOrder_traversal(root, totalNodes);
	int new_k = totalNodes - (original_k - 1);

	kthSmallest(root, new_k, ans);
	return ans;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	TreeNode *root = new TreeNode(4);
	TreeNode *n1 = new TreeNode(2);
	TreeNode *n2 = new TreeNode(9);
	root->left = n1, root->right = n2;

	cout << kthLargest(root, 2);
}