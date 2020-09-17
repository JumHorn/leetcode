#include <queue>
#include <vector>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode *root)
	{
		vector<vector<int>> res;
		queue<TreeNode *> q;
		if (root == nullptr)
			return res;
		q.push(root);
		bool left_to_right = false;
		while (!q.empty())
		{
			int size = q.size();
			res.emplace_back(vector<int>(size));
			left_to_right = !left_to_right;
			for (int i = 0; i < size; ++i)
			{
				auto node = q.front();
				q.pop();
				int index = left_to_right ? i : size - i - 1;
				res.back()[index] = node->val;
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
		return res;
	}
};