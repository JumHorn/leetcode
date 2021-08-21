#include <climits>
#include <stack>
#include <vector>
using namespace std;

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
	TreeNode *bstFromPreorder(vector<int> &preorder)
	{
		stack<TreeNode *> s;
		TreeNode *res = new TreeNode(preorder[0]);
		s.push(res);
		for (int i = 1; i < (int)preorder.size(); ++i)
		{
			TreeNode *node = new TreeNode(preorder[i]), *pre = nullptr;
			while (!s.empty() && s.top()->val < preorder[i])
			{
				pre = s.top();
				s.pop();
			}
			if (pre != nullptr)
				pre->right = node;
			else
				s.top()->left = node;
			s.push(node);
		}
		return res;
	}
};