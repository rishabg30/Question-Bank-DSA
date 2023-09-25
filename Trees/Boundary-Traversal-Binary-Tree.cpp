#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

bool isLeaf(TreeNode* root) {
	if (root->left == NULL && root->right == NULL) {
		return true;
	}
	return false;
}
void addLeafNodes(TreeNode* root, vector<int>&ans) {
	if (isLeaf(root)) {
		ans.push_back(root->val);
		return;
	}
	if (root->left) {
		addLeafNodes(root->left, ans);
	}
	if (root->right) {
		addLeafNodes(root->right, ans);
	}
}
void addLeftBoundary(TreeNode* root, vector<int>&ans) {
	TreeNode *node = root->left;
	while (node != NULL) {
		if (isLeaf(node) == false) {
			ans.push_back(node->val);
		}
		if (node->left) {
			node = node->left;
		}
		else node = node->right;
	}
}
void addRightBoundary(TreeNode* root, vector<int>&ans) {
	TreeNode *node = root->right;
	vector<int>temp;
	while (node != NULL) {
		if (isLeaf(node) == false) {
			temp.push_back(node->val);
		}
		if (node->right) {
			node = node->right;
		}
		else node = node->left;
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		ans.push_back(temp[i]);
	}
}
vector <int> boundaryTraversal(TreeNode *root) {
	vector<int>ans;
	if (root == NULL) {
		return {};
	}
	if (isLeaf(root) == false) {
		ans.push_back(root->val);
	}
	addLeftBoundary(root, ans);
	addLeafNodes(root, ans);
	addRightBoundary(root, ans);
	return ans;
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
	vector<int>ans = boundaryTraversal(root);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;
}