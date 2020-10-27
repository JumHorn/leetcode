
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define trimax(a, b, c) (max(max(a, b), c)) //the maximum of a,b,c

typedef struct pair
{
	int diameter;
	int height;
} pair;

pair postorder(struct TreeNode *root) //{diameter,height}
{
	pair res = {0, 0};
	if (!root)
		return res;
	pair l = postorder(root->left);
	pair r = postorder(root->right);
	res.diameter = trimax(l.diameter, r.diameter, l.height + r.height);
	res.height = 1 + max(l.height, r.height);
	return res;
}

int diameterOfBinaryTree(struct TreeNode *root)
{
	return postorder(root).diameter;
}