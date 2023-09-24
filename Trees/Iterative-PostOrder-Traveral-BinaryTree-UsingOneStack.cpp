#include <bits/stdc++.h>
using namespace std;
//https://www.codingninjas.com/studio/problems/postorder-traversal_2035933?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

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
	stack<TreeNode *>st;
	vector<int>ans;
	TreeNode *curr = root;

	while (curr != NULL || st.size() != 0) {
		if (curr != NULL) {
			st.push(curr);
			curr = curr->left;
		}
		else {
			TreeNode *temp = st.top()->right;
			if (temp == NULL) {
				temp = st.top();
				st.pop();
				ans.push_back(temp->val);
				while (st.size() != 0 && temp == st.top()->right) {
					temp = st.top();
					st.pop();
					ans.push_back(temp->val);
				}
			}
			else {
				curr = temp;
			}
		}
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