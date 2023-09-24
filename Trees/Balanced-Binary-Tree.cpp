#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/balanced-binary-tree/

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

class BTPair {
public:
	bool isBal = true;
	int height = 0;
};
BTPair checkBalanced(TreeNode* root) {
	if (root == NULL) {
		BTPair basePair;
		return basePair;
	}

	BTPair myAns;
	BTPair leftSubtree = checkBalanced(root->left);
	BTPair rightSubtree = checkBalanced(root->right);

	myAns.isBal = leftSubtree.isBal && rightSubtree.isBal;
	if (myAns.isBal == true && abs(leftSubtree.height - rightSubtree.height) <= 1) {
		myAns.height = max(leftSubtree.height, rightSubtree.height) + 1;
	}
	else {
		myAns.isBal = false;
	}
	return myAns;
}
bool isBalanced(TreeNode* root) {
	if (root == NULL) {
		return true;
	}
	BTPair myAns = checkBalanced(root);
	return myAns.isBal;
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
	cout << isBalanced(root) << endl;
}