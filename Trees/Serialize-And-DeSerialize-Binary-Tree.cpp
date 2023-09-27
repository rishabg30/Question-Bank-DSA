#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		//Will use a level-order-traversal to serialize a binary tree
		if (root == NULL) {
			return "";
		}
		string s = "";
		queue<TreeNode *>q;
		q.push(root);
		while (q.size() != 0) {
			TreeNode *node = q.front();
			q.pop();
			if (node == NULL) {
				s += "#,";
			}
			else {
				s += to_string(node->val) + ",";
			}
			if (node != NULL) {
				q.push(node->left);
				q.push(node->right);
			}
		}
		return s;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		/*
		To deserialize a string back to tree what we can do is
		-We will maintain a queue data structure and inside it push the first char which is the root
		 of the tree.

		 Now start iterating inside the queue till it becomes empty.
		-The next char will always be the left child and next will always be the right child.
		*/
		if (data.size() == 0)return NULL;
		stringstream s(data);
		string str;
		getline(s, str, ','); // str gets the first char of the stringstream

		TreeNode *root = new TreeNode(stoi(str));
		queue<TreeNode *>q;
		q.push(root);

		while (q.size() != 0) {
			TreeNode *node = q.front();
			q.pop();
			getline(s, str, ','); // str gets next char of the stringstream
			if (str == "#") {
				node->left = NULL;
			}
			else {
				TreeNode *leftNode = new TreeNode(stoi(str));
				node->left = leftNode;
				q.push(leftNode);
			}

			getline(s, str, ',');
			if (str == "#") {
				node->right = NULL;
			}
			else {
				TreeNode *rightNode = new TreeNode(stoi(str));
				node->right = rightNode;
				q.push(rightNode);
			}
		}
		return root;
	}
};
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}