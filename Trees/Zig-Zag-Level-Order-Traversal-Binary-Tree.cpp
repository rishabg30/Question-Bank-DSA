#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

void printArray_1D(vector<int>&arr) {
	for (auto it : arr) {
		cout << it << " ";
	}
	cout << endl;
}

void printArray_2D(vector<vector<int>>&arr) {
	for (auto it : arr) {
		for (auto it2 : it) {
			cout << it2 << " ";
		}
		cout << endl;
	}
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	if (root == NULL) {
		return {};
	}
	vector<vector<int>>ans;
	queue<TreeNode* >q;
	q.push(root);
	int counter = 0;

	while (q.size() != 0) {
		int curr_size = q.size();
		vector<int>levelOrder(curr_size);

		for (int i = 0; i < curr_size; i++) {
			TreeNode * node = q.front();
			q.pop();
			if (counter % 2 == 0) {
				levelOrder[i] = node->val;
			}
			else {
				levelOrder[levelOrder.size() - i - 1] = node->val;
			}
			if (node->left) {
				q.push(node->left);
			}
			if (node->right) {
				q.push(node->right);
			}
		}
		counter++;
		ans.push_back(levelOrder);
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
	vector<vector<int>>ans = zigzagLevelOrder(root);
	// vector<int>ans = zigzagLevelOrder(root);
	// printArray_1D(ans);

	printArray_2D(ans);
}
