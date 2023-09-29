#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/binary-search-tree-iterator/description/

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
private: stack<TreeNode *>myStack;
public:
	BSTIterator(TreeNode* root) {
		pushAll(root);
	}

	int next() {
		TreeNode *curr = myStack.top();
		myStack.pop();
		pushAll(curr->right);
		return curr->val;
	}

	bool hasNext() {
		return (myStack.size() != 0) ? true : false;
	}

private:
	//Push all the left's
	void pushAll(TreeNode *root) {
		while (root != NULL) {
			myStack.push(root);
			root = root->left;
		}
	}
};
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}