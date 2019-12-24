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

struct TreeNode* postorder(struct TreeNode* root, int layer, int maxheight)
{
	if (!root)
		return root;
	if (layer == maxheight)
		return root;
	struct TreeNode* leftnode = postorder(root->left, layer + 1, maxheight);
	struct TreeNode* rightnode = postorder(root->right, layer + 1, maxheight);
	if (!leftnode && !rightnode)
		return root;
	if (!leftnode)
		return leftnode;
	return rightnode;
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root)
{
	if (!root)
		return root;
	int h = height(root);
	return postorder(root, 1, h);
}
