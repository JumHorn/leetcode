#include <algorithm>
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
	long long kthLargestLevelSum(TreeNode *root, int k)
	{
		vector<long long> sum;
		preorder(root, sum, 0);
		if (sum.size() < k)
			return -1;
		nth_element(sum.begin(), sum.begin() + k - 1, sum.end(), greater<long long>());
		return sum[k - 1];
	}

	void preorder(TreeNode *root, vector<long long> &sum, int layer)
	{
		if (root == nullptr)
			return;
		if (layer >= sum.size())
			sum.push_back(0 + root->val);
		else
			sum[layer] += root->val;
		preorder(root->left, sum, layer + 1);
		preorder(root->right, sum, layer + 1);
	}
};