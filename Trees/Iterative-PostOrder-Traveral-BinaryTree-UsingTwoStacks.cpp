#include <bits/stdc++.h>
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};
vector<int> iterative_PostOrder_Traversal(TreeNode* root) {
	if (root == NULL) {
		return {};
	}
	vector<int>ans;
	stack<TreeNode *>st1, st2;
	st1.push(root);

	while (st1.size() != 0) {
		TreeNode *node = st1.top();
		st1.pop();
		//Put it in stack 2
		st2.push(node);

		//Check if left child present push it
		if (node->left) {
			st1.push(node->left);
		}
		if (node->right) {
			st1.push(node->right);
		}
	}

	while (st2.size() != 0) {
		ans.push_back(st2.top()->val);
		st2.pop();
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
	vector<int>postOrder = iterative_PostOrder_Traversal(root);
	for (auto it : postOrder) {
		cout << it << " ";
	}
	cout << endl;
}