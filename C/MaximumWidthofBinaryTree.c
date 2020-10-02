
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

void preorder(struct TreeNode *root, int height, long index, int *layer, int *layersize, int *width)
{
	if (!root)
		return;
	if (height >= *layersize)
		layer[(*layersize)++] = index;
	*width = max(*width, (int)index - layer[height] + 1);
	preorder(root->left, height + 1, index * 2, layer, layersize, width);
	preorder(root->right, height + 1, index * 2 + 1, layer, layersize, width);
}

int widthOfBinaryTree(struct TreeNode *root)
{
	int layer[3000], layersize = 0; //each layer's left most index
	int res = 0;
	preorder(root, 0, 0, layer, &layersize, &res);
	return res;
}