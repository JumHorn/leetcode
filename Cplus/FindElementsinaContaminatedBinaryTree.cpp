#include <unordered_set>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class FindElements
{
public:
	FindElements(TreeNode *root)
	{
		if (root != NULL)
		{
			root->val = 0;
			dfs(root);
		}
	}

	void dfs(TreeNode *root)
	{
		if (root == NULL)
			return;
		s.insert(root->val);
		if (root->left != NULL)
		{
			root->left->val = 2 * root->val + 1;
			dfs(root->left);
		}
		if (root->right != NULL)
		{
			root->right->val = 2 * root->val + 2;
			dfs(root->right);
		}
	}

	bool find(int target)
	{
		return s.find(target) != s.end();
	}

private:
	unordered_set<int> s;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
