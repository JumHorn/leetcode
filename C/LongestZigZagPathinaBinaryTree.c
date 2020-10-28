
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define trimax(a, b, c) (max(max(a, b), c))  //the maximum of a,b,c

typedef struct pair
{
	int left;
	int right;
} pair;

pair postorder(struct TreeNode *root, int *path)  //{left zag,right zag}
{
	pair res = {0, 0};
	if (!root)
		return res;
	pair l = postorder(root->left, path);
	pair r = postorder(root->right, path);
	*path = trimax(*path, l.right, r.left);
	res.left = 1 + l.right;
	res.right = 1 + r.left;
	return res;
}

int longestZigZag(struct TreeNode *root)
{
	int res = 0;
	postorder(root, &res);
	return res;
}
