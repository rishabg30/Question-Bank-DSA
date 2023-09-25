#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

void printArray_2D(vector<vector<int>>&arr) {
	for (auto it : arr) {
		for (auto it2 : it) {
			cout << it2 << " ";
		}
		cout << endl;
	}
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
	map<int, map<int, multiset<int>>>mp;
	queue<pair<TreeNode*, pair<int, int>>>q;
	q.push({root, {0, 0}});

	while (q.size() != 0) {
		auto it = q.front();
		q.pop();
		TreeNode *node = it.first;
		int x_axis = it.second.first, y_axis = it.second.second;
		mp[x_axis][y_axis].insert(node->val);

		if (node->left) {
			q.push({node->left, {x_axis - 1, y_axis + 1}});
		}
		if (node->right) {
			q.push({node->right, {x_axis + 1, y_axis + 1}});
		}
	}

	vector<vector<int>>ans;
	for (auto it : mp) {
		vector<int>v;
		for (auto it2 : it.second) {
			for (auto it3 : it2.second) {
				v.push_back(it3);
			}
		}
		ans.push_back(v);
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
	vector<vector<int>>ans = verticalTraversal(root);
	printArray_2D(ans);
}