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
	vector<int> inorderTraversal(TreeNode *root)
	{
		stack<TreeNode *> s;
		vector<int> res;
		TreeNode *node = root;
		while (node || !s.empty())
		{
			if (node != nullptr)
			{
				s.push(node);
				node = node->left;
			}
			else
			{
				node = s.top();
				s.pop();
				res.push_back(node->val);
				node = node->right;
			}
		}
		return res;
	}
};