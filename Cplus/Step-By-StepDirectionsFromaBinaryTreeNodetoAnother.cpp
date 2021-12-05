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
	string getDirections(TreeNode *root, int startValue, int destValue)
	{
		TreeNode *parent = getRoot(root, startValue, destValue);
		string startpath, destpath;
		pathToStart(parent, startValue, startpath);
		pathToDest(parent, destValue, destpath);
		return startpath + destpath;
	}

	bool pathToStart(TreeNode *root, int start, string &startpath)
	{
		if (root == nullptr)
			return false;
		if (root->val == start)
			return true;
		startpath.push_back('U');
		if (pathToStart(root->left, start, startpath) ||
			pathToStart(root->right, start, startpath))
			return true;
		startpath.pop_back();
		return false;
	}

	bool pathToDest(TreeNode *root, int dest, string &destpath)
	{
		if (root == nullptr)
			return false;
		if (root->val == dest)
			return true;
		destpath.push_back('L');
		if (pathToDest(root->left, dest, destpath))
			return true;
		destpath.pop_back();

		destpath.push_back('R');
		if (pathToDest(root->right, dest, destpath))
			return true;
		destpath.pop_back();
		return false;
	}

	// post order get root of start and dest
	TreeNode *getRoot(TreeNode *root, int start, int dest)
	{
		if (root == nullptr)
			return nullptr;
		if (root->val == start || root->val == dest)
			return root;
		auto left = getRoot(root->left, start, dest);
		auto right = getRoot(root->right, start, dest);
		if (left != nullptr && right != nullptr)
			return root;
		if (left != nullptr)
			return left;
		if (right != nullptr)
			return right;
		return nullptr;
	}
};