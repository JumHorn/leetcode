#include <vector>
using namespace std;

/*
keep decreasing stack
*/

// Definition for a binary tree node.
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
	TreeNode *constructMaximumBinaryTree(vector<int> &nums)
	{
		vector<TreeNode *> stk;
		for (auto n : nums)
		{
			TreeNode *node = new TreeNode(n);
			while (!stk.empty() && stk.back()->val < n)
			{
				node->left = stk.back();
				stk.pop_back();
			}
			if (!stk.empty())
				stk.back()->right = node;
			stk.push_back(node);
		}
		return stk.front();
	}
};