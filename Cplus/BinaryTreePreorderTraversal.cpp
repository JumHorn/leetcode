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
	vector<int> preorderTraversal(TreeNode *root)
	{
		vector<int> res;
		stack<TreeNode *> s;
		if (root == nullptr)
			return res;
		s.push(root);
		while (!s.empty())
		{
			struct TreeNode *node = s.top();
			s.pop();
			res.push_back(node->val);
			if (node->right != nullptr)
				s.push(node->right);
			if (node->left != nullptr)
				s.push(node->left);
		}
		return res;
	}
};