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
		saveToStack(root);
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode *root = s.top();
		s.pop();
		saveToStack(root->right);
		return root->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !s.empty();
	}

private:
	void saveToStack(TreeNode *root)
	{
		for (; root != nullptr; root = root->left)
			s.push(root);
	}

	stack<TreeNode *> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */