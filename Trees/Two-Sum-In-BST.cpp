#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};
class BSTIterator {
private:
	stack<TreeNode *>myStack;
	bool reverse = true;
	//reverse->true->before()
	//reverse->false->next()
public:
	BSTIterator(TreeNode *root, bool isReverse) {
		reverse = isReverse;
		pushAll(root);
	}
	int next() {
		TreeNode *curr = myStack.top();
		myStack.pop();
		if (reverse == true) {
			pushAll(curr->left);
		}
		else {
			pushAll(curr->right);
		}
		return curr->val;
	}
private:
	void pushAll(TreeNode *node) {
		while (node != NULL) {
			myStack.push(node);
			if (reverse == true) {
				node = node->right;
			}
			else node = node->left;
		}
	}
};
bool findTarget(TreeNode* root, int k) {
	if (root == NULL)return false;
	BSTIterator l(root, false);
	BSTIterator r(root, true);

	int i = l.next(), j = r.next();
	while (i < j) {
		if (i + j == k)return true;
		else if (i + j < k) {
			i = l.next();
		}
		else {
			j = r.next();
		}
	}
	return false;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	TreeNode *root = new TreeNode(8);
	TreeNode *n1 = new TreeNode(3);
	TreeNode *n2 = new TreeNode(10);
	root->left = n1, root->right = n2;

	TreeNode *n3 = new TreeNode(1);
	TreeNode *n4 = new TreeNode(6);
	TreeNode *n5 = new TreeNode(14);
	n1->left = n3, n1->right = n4;
	n2->right = n5;

	TreeNode *n6 = new TreeNode(4);
	TreeNode *n7 = new TreeNode(7);
	TreeNode *n8 = new TreeNode(13);
	n4->left = n6, n4->right = n7;
	n5->left = n8;
	cout << findTarget(root, 23) << endl;
}