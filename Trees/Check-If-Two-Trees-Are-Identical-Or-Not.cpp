#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/same-tree/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

bool isSameTree(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL && root2 == NULL) {
		return true;
	}
	else if ((root1 == NULL && root2 != NULL) ||
	         (root1 != NULL && root2 == NULL)) {
		return false;
	}
	if (root1->val != root2->val) {
		return false;
	}

	return isSameTree(root1->left, root2->left) &&
	       isSameTree(root1->right, root2->right);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	TreeNode *root1 = new TreeNode(1);
	TreeNode *n1 = new TreeNode(2);
	TreeNode *n2 = new TreeNode(3);
	root1->left = n1, root1->right = n2;

	TreeNode *root2 = new TreeNode(1);
	TreeNode *m1 = new TreeNode(2);
	TreeNode *m2 = new TreeNode(3);
	root2->left = m1, root2->right = m2;
	cout << isSameTree(root1, root2) << endl;
}