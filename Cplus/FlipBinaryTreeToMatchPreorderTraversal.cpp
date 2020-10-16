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
	vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
	{
		vector<int> res;
		int index = -1;
		if (backTracking(root, voyage, index, res))
			return res;
		return {-1};
	}

	bool backTracking(TreeNode *root, vector<int> &voyage, int &index, vector<int> &res)
	{
		if (root == nullptr)
			return true;
		if (root->val != voyage[index + 1])
			return false;
		++index;
		if (backTracking(root->left, voyage, index, res))
		{
			if (backTracking(root->right, voyage, index, res))
				return true;
		}

		res.push_back(root->val);
		if (backTracking(root->right, voyage, index, res))
		{
			if (backTracking(root->left, voyage, index, res))
				return true;
		}
		res.pop_back();
		--index;
		return false;
	}
};