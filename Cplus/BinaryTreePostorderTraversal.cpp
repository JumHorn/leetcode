#include <vector>
#include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> res;
		stack<TreeNode *> s;
		if (root == NULL)
			return res;
		s.push(root);
		TreeNode *pre = root, *curr = root;
		while (!s.empty())
		{
			curr = s.top();
			if ((curr->left == NULL && curr->right == NULL) || (curr->left == pre || curr->right == pre))
			{
				pre = curr;
				res.push_back(curr->val);
				s.pop();
			}
			else
			{
				if (curr->right != NULL)
					s.push(curr->right);
				if (curr->left != NULL)
					s.push(curr->left);
			}
		}
		return res;
	}
};