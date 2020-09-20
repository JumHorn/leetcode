#include <stack>
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

class BSTIterator
{
public:
	BSTIterator(TreeNode *root)
	{
		while (root != nullptr)
		{
			s.push(root);
			root = root->left;
		}
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode *root = s.top();
		s.pop();
		int res = root->val;
		root = root->right;
		while (root != nullptr)
		{
			s.push(root);
			root = root->left;
		}
		return res;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !s.empty();
	}

private:
	stack<TreeNode *> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */