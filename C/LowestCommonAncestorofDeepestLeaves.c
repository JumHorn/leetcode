//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct NodeDepth
{
	struct TreeNode* node;
	int height;
};

struct NodeDepth postorder(struct TreeNode* root)
{
	if (!root)
	{
		struct NodeDepth res = {root, 0};
		return res;
	}
	struct NodeDepth leftnode = postorder(root->left);
	struct NodeDepth rightnode = postorder(root->right);
	if (leftnode.height < rightnode.height)
	{
		struct NodeDepth res = {rightnode.node, rightnode.height + 1};
		return res;
	}
	if (leftnode.height > rightnode.height)
	{
		struct NodeDepth res = {leftnode.node, leftnode.height + 1};
		return res;
	}
	struct NodeDepth res = {root, leftnode.height + 1};
	return res;
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root)
{
	if (!root)
		return root;
	return postorder(root).node;
}
