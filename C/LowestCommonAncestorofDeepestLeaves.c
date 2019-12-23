#define max(a, b) (((a) > (b)) ? (a) : (b))

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int height(struct TreeNode* root)
{
	if (!root)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

bool postorder(struct TreeNode* root, int layer, int maxheight)
{
	if (!root)
		return false;
	if (layer == maxheight)
		return true;
	postorder(root->left, layer + 1, maxheight);
	postorder(root->right, layer + 1, maxheight);
	return true;
}

struct TreeNode* deepest(struct TreeNode* root, int maxheight)
{
	int leftheight = height(root->left);
	int rightheight = height(root->right);
	if (leftheight < maxheight)
		return deepest(root->right, maxheight - 1);
	if (rightheight < maxheight)
		return deepest(root->left, maxheight - 1);
	return root;
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root)
{
	if (!root)
		return root;
	int h = height(root);
	return deepest(root, h - 1);
}

