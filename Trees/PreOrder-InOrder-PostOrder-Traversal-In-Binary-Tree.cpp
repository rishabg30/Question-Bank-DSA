#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/tree-traversals_981269?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

class TreeNode {
public:
	int val;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int val) {
		this->val = val;
	}
};

vector<vector<int>> getTreeTraversal(TreeNode *root) {
	if (root == NULL) {
		return {{}};
	}
	vector<int>preOrder, inOrder, postOrder;
	stack<pair<TreeNode*, int>>st;
	st.push(make_pair(root, 1));

	while (st.size() != 0) {
		auto it = st.top();
		st.pop();
		//If num == 1, this means it is preOrder
		if (it.second == 1) {
			preOrder.push_back(it.first->val);
			it.second++;
			st.push(it);
			if (it.first->left) {
				st.push(make_pair(it.first->left, 1));
			}
		}

		//If num == 2, this means it is inOrder
		else if (it.second == 2) {
			inOrder.push_back(it.first->val);
			it.second++;
			st.push(it);
			if (it.first->right) {
				st.push(make_pair(it.first->right, 1));
			}
		}

		//If num == 3, this means it is postOrder
		else {
			postOrder.push_back(it.first->val);
		}
	}
	vector<vector<int>>ans;
	ans.push_back(preOrder);
	ans.push_back(inOrder);
	ans.push_back(postOrder);
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
	vector<vector<int>>ans = getTreeTraversal(root);
	for (auto it : ans) {
		for (auto it2 : it) {
			cout << it2 << " ";
		}
		cout << endl;
	}
}