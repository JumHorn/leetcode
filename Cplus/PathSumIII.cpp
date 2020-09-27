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
		unordered_map<int, int> count = {{0, 1}}; //{val,count}
		return preorder(root, 0, sum, count);
	}

	int preorder(TreeNode *root, int sum, int target, unordered_map<int, int> &count)
	{
		if (root == nullptr)
			return 0;
		sum += root->val;
		int res = count[sum - target];
		++count[sum];
		res += preorder(root->left, sum, target, count);
		res += preorder(root->right, sum, target, count);
		--count[sum];
		return res;
	}
};