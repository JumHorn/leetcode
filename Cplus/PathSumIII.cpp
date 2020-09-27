#include <unordered_map>
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
	int pathSum(TreeNode *root, int sum)
	{
		int res = 0;
		postorder(root, sum, res);
		return res;
	}

	unordered_map<int, int> postorder(TreeNode *root, int sum, int &count)
	{
		if (root == nullptr)
			return {};
		auto left = postorder(root->left, sum, count);
		auto right = postorder(root->right, sum, count);
		unordered_map<int, int> res;
		for (auto l : left)
			res[l.first + root->val] += l.second;
		for (auto r : right)
			res[r.first + root->val] += r.second;
		++res[root->val];
		count += res[sum];
		return res;
	}
};