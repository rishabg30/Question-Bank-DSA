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

bool getPath(TreeNode *root, int node, vector<int>&ds) {
	if (root == NULL) {
		return false;
	}
	ds.push_back(root->val);
	if (root->val == node) {
		return true;
	}
	if (getPath(root->left, node, ds) == true ||
	        getPath(root->right, node, ds) == true) {
		return true;
	}
	ds.pop_back();
	return false;
}
vector<int>rootToNodePath(TreeNode *root, int node) {
	vector<int>ds;
	if (root == NULL) {
		return {};
	}
	getPath(root, node, ds);
	return ds;
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
	vector<int>ans = rootToNodePath(root, 9);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;
}