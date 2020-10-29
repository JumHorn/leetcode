
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

typedef struct info
{
	int xparent;
	int xdepth;
	int yparent;
	int ydepth;
} info;

class Solution
{
public:
	bool isCousins(TreeNode *root, int x, int y)
	{
		info data = {0, 0, 1, 1}; //init different
		preorder(root, -1, 0, x, y, data);
		return data.xdepth == data.ydepth && data.xparent != data.yparent;
	}

	void preorder(struct TreeNode *root, int parent, int layer, int x, int y, info &data)
	{
		if (!root)
			return;
		if (root->val == x)
		{
			data.xdepth = layer;
			data.xparent = parent;
		}
		else if (root->val == y)
		{
			data.ydepth = layer;
			data.yparent = parent;
		}
		preorder(root->left, root->val, layer + 1, x, y, data);
		preorder(root->right, root->val, layer + 1, x, y, data);
	}
};