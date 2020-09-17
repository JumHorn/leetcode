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
	TreeNode *sortedArrayToBST(vector<int> &nums)
	{
		return recursive(nums, 0, nums.size());
	}

	TreeNode *recursive(vector<int> &nums, int first, int last) //[first,last)
	{
		if (first >= last)
			return nullptr;
		int mi = (last - first) / 2 + first;
		TreeNode *root = new TreeNode(nums[mi]);
		root->left = recursive(nums, first, mi);
		root->right = recursive(nums, mi + 1, last);
		return root;
	}
};