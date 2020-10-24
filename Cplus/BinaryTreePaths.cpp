#include <string>
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
	vector<string> binaryTreePaths(TreeNode *root)
	{
		vector<string> res;
		string instance;
		preorder(root, instance, res);
		return res;
	}

	void preorder(TreeNode *root, string instance, vector<string> &data)
	{
		if (root == nullptr)
			return;
		instance += (instance.empty() ? "" : "->") + to_string(root->val);
		if (root->left == root->right)
		{
			data.push_back(instance);
			return;
		}
		preorder(root->left, instance, data);
		preorder(root->right, instance, data);
	}
};