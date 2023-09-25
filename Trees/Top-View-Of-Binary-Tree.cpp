#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

vector<int> topView(TreeNode *root) {
	vector<int>ans;
	if (root == NULL) {
		return {};
	}
	queue<pair<TreeNode*, int>>q;
	map<int, TreeNode*>mp;
	q.push({root, 0});

	while (q.size() != 0) {
		auto it = q.front();
		q.pop();
		TreeNode *node = it.first;
		int x_axis = it.second;
		if (mp.find(x_axis) == mp.end()) {
			mp.insert({x_axis, node});
		}

		if (node->left) {
			q.push({node->left, x_axis - 1});
		}
		if (node->right) {
			q.push({node->right, x_axis + 1});
		}
	}
	for (auto it : mp) {
		ans.push_back(it.second->val);
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
	vector<int>ans = topView(root);
	for (auto it : ans) {
		cout << it << " ";
	}
	cout << endl;
}