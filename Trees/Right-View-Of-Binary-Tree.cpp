#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/binary-tree-right-side-view/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

vector<int> rightSideView(TreeNode* root) {
	vector<int>ans;
	if (root == NULL) {
		return {};
	}
	queue<TreeNode* >q;
	q.push(root);
	while (q.size() != 0) {
		int curr_size = q.size(), curr_ans = 0;
		for (int i = 0; i < curr_size; i++) {
			TreeNode * node = q.front();
			q.pop();
			curr_ans = node->val;

			if (node->left) {
				q.push(node->left);
			}
			if (node->right) {
				q.push(node->right);
			}
		}
		ans.push_back(curr_ans);
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

	TreeNode *n3 = new TreeNode(5);
	TreeNode *n4 = new TreeNode(6);
	n1->right = n3, n2->left = n4;

	vector<int>ans = rightSideView(root);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;
}