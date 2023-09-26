#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/time-to-burn-tree_1469067?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

TreeNode *markParents(TreeNode *root, map<TreeNode *, TreeNode *>&parent_track, int startNode) {
	if (root == NULL) {
		return root;
	}
	queue<TreeNode *>q;
	q.push(root);
	TreeNode *mystartNode;
	while (q.size() != 0) {
		TreeNode *node = q.front();
		if (node->val == startNode) {
			mystartNode = node;
		}
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
	return mystartNode;
}
int timeToBurnTree(TreeNode *root, int startNode) {
	if (root == NULL)return 0;
	map<TreeNode *, TreeNode *>parent_track;
	TreeNode *start = markParents(root, parent_track, startNode);

	map<TreeNode *, bool>visited;
	queue<TreeNode *>q;
	q.push(start);
	visited[start] = true;

	int max_time = 0;
	while (q.size() != 0) {
		int curr_size = q.size();
		for (int i = 0; i < curr_size; i++) {
			TreeNode *node = q.front();
			q.pop();

			//Left Child [downwards]
			if (node->left && visited[node->left] == false) {
				q.push(node->left);
				visited[node->left] = true;
			}
			//Right Child [downwards]
			if (node->right && visited[node->right] == false) {
				q.push(node->right);
				visited[node->right] = true;
			}
			//Parent [upwards]
			if (parent_track[node] && visited[parent_track[node]] == false) {
				q.push(parent_track[node]);
				visited[parent_track[node]] = true;
			}
		}
		max_time++;
	}
	return max_time - 1;
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
	cout << timeToBurnTree(root, n2->val) << endl;
}