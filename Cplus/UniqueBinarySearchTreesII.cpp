#include <algorithm>
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
	vector<TreeNode *> generateTrees(int n)
	{
		if (n == 0)
			return {};
		return recursive(1, n);
	}

	vector<TreeNode *> recursive(int first, int last) //[first,last] closed range
	{
		if (first > last)
			return {nullptr};
		vector<TreeNode *> res;
		for (int i = first; i <= last; ++i)
		{
			vector<TreeNode *> left = recursive(first, i - 1);
			vector<TreeNode *> right = recursive(i + 1, last);
			for (auto l : left)
			{
				for (auto r : right)
				{
					TreeNode *root = new TreeNode(i);
					root->left = l;
					root->right = r;
					res.push_back(root);
				}
			}
		}
		return res;
	}
};