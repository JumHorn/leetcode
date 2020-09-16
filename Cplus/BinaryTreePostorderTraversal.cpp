#include <stack>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> res;
		stack<TreeNode *> s;
		if (root == nullptr)
			return res;
		s.push(root);
		TreeNode *pre = root, *curr = root;
		while (!s.empty())
		{
			curr = s.top();
			if ((curr->left == nullptr && curr->right == nullptr) || (curr->left == pre || curr->right == pre))
			{
				pre = curr;
				res.push_back(curr->val);
				s.pop();
			}
			else
			{
				if (curr->right != nullptr)
					s.push(curr->right);
				if (curr->left != nullptr)
					s.push(curr->left);
			}
		}
		return res;
	}
};