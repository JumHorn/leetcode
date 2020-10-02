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
	TreeNode *constructMaximumBinaryTree(vector<int> &nums)
	{
		return preorder(nums, 0, nums.size());
	}

	TreeNode *preorder(vector<int> &nums, int first, int last)
	{
		if (last <= first)
			return nullptr;
		int maxindex = first;
		for (int i = first + 1; i < last; ++i)
		{
			if (nums[maxindex] < nums[i])
				maxindex = i;
		}
		TreeNode *root = new TreeNode(nums[maxindex]);
		root->left = preorder(nums, first, maxindex);
		root->right = preorder(nums, maxindex + 1, last);
		return root;
	}
};