#include <algorithm>
#include <queue>
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
	int widthOfBinaryTree(TreeNode *root)
	{
		int res = 0;
		queue<pair<TreeNode *, int>> q; //{node,index}
		q.push({root, 0});
		while (!q.empty())
		{
			int size = q.size();
			if (size == 1)
				q.front().second = 0;
			res = max(res, q.back().second - q.front().second + 1);
			int base = q.front().second;
			while (--size >= 0)
			{
				TreeNode *node = q.front().first;
				int index = q.front().second - base;
				q.pop();
				if (node->left != nullptr)
					q.push({node->left, index * 2});
				if (node->right != nullptr)
					q.push({node->right, index * 2 + 1});
			}
		}
		return res;
	}
};