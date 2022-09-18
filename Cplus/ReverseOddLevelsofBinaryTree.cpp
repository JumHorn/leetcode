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
	TreeNode *reverseOddLevels(TreeNode *root)
	{
		vector<TreeNode *> q;
		q.push_back(root);
		bool odd = false;
		for (int left = 0, right = 1; left < right;)
		{
			odd = !odd;
			for (int i = left; i < right; ++i)
			{
				if (q[i]->left != nullptr)
					q.push_back(q[i]->left);
				if (q[i]->right != nullptr)
					q.push_back(q[i]->right);
			}
			left = right;
			right = q.size();
			if (odd)
			{
				for (int i = left, j = right - 1; i < j; ++i, --j)
					swap(q[i]->val, q[j]->val);
			}
		}
		return root;
	}
};