#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

void markParents(TreeNode *root, map<TreeNode*, TreeNode*>&parent_track) {
	if (root == NULL)return;
	queue<TreeNode *>q;
	q.push(root);
	while (q.size() != 0) {
		TreeNode *node = q.front();
		q.pop();
		if (node->left) {
			parent_track[node->left] = node;
			q.push(node->left);
		}
		if (node->right) {
			parent_track[node->right] = node;
			q.push(node->right);
		}
	}
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
	if (root == NULL) {
		return {};
	}
	map<TreeNode *, TreeNode*>parent_track;
	markParents(root, parent_track);

	map<TreeNode*, bool>visited;
	queue<TreeNode *>q;
	q.push(target);
	visited[target] = true;
	int curr_level = 0;
	while (q.size() != 0) {
		int curr_size = q.size();
		if (curr_level == k)break;

		curr_level++;
		for (int i = 0; i < curr_size; i++) {
			TreeNode *node = q.front();
			q.pop();
			if (node->left && visited[node->left] == false) {
				q.push(node->left);
				visited[node->left] = true;
			}
			if (node->right && visited[node->right] == false) {
				q.push(node->right);
				visited[node->right] = true;
			}
			if (parent_track[node] && visited[parent_track[node]] == false) {
				q.push(parent_track[node]);
				visited[parent_track[node]] = true;
			}
		}
	}
	vector<int>ans;
	while (q.size() != 0) {
		ans.push_back(q.front()->val);
		q.pop();
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
	vector<int>ans = distanceK(root, n2, 2);
	for (auto it : ans) {
		cout << it << " ";
	}
}