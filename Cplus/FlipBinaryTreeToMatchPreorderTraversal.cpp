#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)
	{
		vector<int> res;
		int index = -1;
		if (backTracking(root, voyage, index, res))
			return res;
		return {-1};
	}

	bool backTracking(TreeNode* root, vector<int>& voyage, int& index, vector<int>& res)
	{
		if (root == NULL)
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
		--index;
		res.pop_back();
		return false;
	}
};

