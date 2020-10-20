#include <unordered_set>
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
	vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
	{
		vector<TreeNode *> res;
		unordered_set<int> delets(to_delete.begin(), to_delete.end());
		preorder(root, true, delets, res);
		return res;
	}

	TreeNode *preorder(TreeNode *root, bool parentDeleted, unordered_set<int> &deletes, vector<TreeNode *> &forest)
	{
		if (root == nullptr)
			return nullptr;
		if (deletes.find(root->val) == deletes.end())
		{
			if (parentDeleted)
				forest.push_back(root);
			parentDeleted = false;
		}
		else
			parentDeleted = true;
		root->left = preorder(root->left, parentDeleted, deletes, forest);
		root->right = preorder(root->right, parentDeleted, deletes, forest);
		return parentDeleted ? nullptr : root;
	}
};