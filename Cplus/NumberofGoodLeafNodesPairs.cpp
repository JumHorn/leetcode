#include <unordered_map>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	int countPairs(TreeNode* root, int distance)
	{
		int res = 0;
		postorder(root, distance, res);
		return res;
	}

	unordered_map<TreeNode*, int> postorder(TreeNode* root, int distance, int& res)  //return type {leaf node,distance}
	{
		if (root == NULL)
			return {};
		auto left = postorder(root->left, distance, res);
		auto right = postorder(root->right, distance, res);
		if (left.empty() && right.empty())
			return {{root, 0}};
		incMap(left);
		incMap(right);
		if (left.empty())
			return right;
		if (right.empty())
			return left;
		for (auto& n : left)
		{
			for (auto& m : right)
			{
				if (n.second + m.second <= distance)
					++res;
			}
		}
		for (auto& n : right)
			left[n.first] = n.second;
		return left;
	}

	void incMap(unordered_map<TreeNode*, int>& m)
	{
		for (auto& n : m)
			++n.second;
	}
};
