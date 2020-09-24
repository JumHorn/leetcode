
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct pair
{
	int rob;
	int notrob;
} pair;

pair postorder(struct TreeNode *root)
{
	pair res;
	if (!root)
	{
		res.rob = res.notrob = 0;
		return res;
	}
	pair l = postorder(root->left);
	pair r = postorder(root->right);
	res.rob = root->val + l.notrob + r.notrob;
	res.notrob = max(l.rob, l.notrob) + max(r.rob, r.notrob);
	return res;
}

int rob(struct TreeNode *root)
{
	pair res = postorder(root);
	return max(res.rob, res.notrob);
}
