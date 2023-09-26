#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-width-of-binary-tree/description/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

int widthOfBinaryTree(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int ans = 0;
	//{TreeNode*, index}
	queue<pair<TreeNode*, int>>q;
	q.push({root, 0});

	while (q.size() != 0) {
		int curr_size = q.size();
		// int min_index = q.front().second; //to make the index starting from 0
		int first = 0, last = 0;
		for (int i = 0; i < curr_size; i++) {
			TreeNode *node = q.front().first;
			// int updated_index = q.front().second - min_index;
			int updated_index = q.front().second;
			q.pop();
			if (i == 0) {
				first = updated_index;
			}
			if (i == curr_size - 1) {
				last = updated_index;
			}

			if (node->left) {
				q.push({node->left, (long long)2 * updated_index + 1});
			}
			if (node->right) {
				q.push({node->right, (long long)2 * updated_index + 2});
			}
		}
		ans = max(ans, last - first + 1);
	}
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
	cout << widthOfBinaryTree(root);
}