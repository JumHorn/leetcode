
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
	TreeNode *deleteNode(TreeNode *root, int key)
	{
		if (root == nullptr)
			return nullptr;
		if (root->val == key)
		{
			if (root->right == nullptr)
				root = root->left;
			else
			{
				TreeNode **node = &root->right;
				while ((*node)->left)
					node = &(*node)->left;
				root->val = (*node)->val;
				*node = (*node)->right; //memory leak
			}
		}
		else if (root->val > key)
			root->left = deleteNode(root->left, key);
		else
			root->right = deleteNode(root->right, key);
		return root;
	}
};