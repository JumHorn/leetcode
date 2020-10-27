#include <sstream>
#include <string>
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
	string tree2str(TreeNode *t)
	{
		stringstream ss;
		preorder(t, ss);
		return ss.str();
	}

	void preorder(TreeNode *root, stringstream &ss)
	{
		if (root == nullptr)
			return;
		ss << root->val;
		if (root->left != nullptr)
		{
			ss << '(';
			preorder(root->left, ss);
			ss << ')';
		}
		if (root->right != nullptr)
		{
			if (root->left == nullptr)
				ss << "()";
			ss << '(';
			preorder(root->right, ss);
			ss << ')';
		}
	}
};