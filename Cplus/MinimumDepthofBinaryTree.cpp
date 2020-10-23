#include <queue>
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
	int minDepth(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		queue<TreeNode *> q;
		q.push(root);
		int res = 0;
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				TreeNode *node = q.front();
				q.pop();
				if (node->left == node->right)
					return res;
				if (node->left != nullptr)
					q.push(node->left);
				if (node->right != nullptr)
					q.push(node->right);
			}
		}
		return -1;
	}
};