#include <unordered_set>
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

class FindElements
{
public:
	FindElements(TreeNode *root)
	{
		if (root != nullptr)
		{
			root->val = 0;
			preorder(root);
		}
	}

	void preorder(TreeNode *root)
	{
		if (root == nullptr)
			return;
		s.insert(root->val);
		if (root->left != nullptr)
		{
			root->left->val = 2 * root->val + 1;
			preorder(root->left);
		}
		if (root->right != nullptr)
		{
			root->right->val = 2 * root->val + 2;
			preorder(root->right);
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