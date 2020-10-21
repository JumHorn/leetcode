#include <stdbool.h>

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
	int nodecount;
	bool result;
	bool flag;  //stop recusion
} pair;

pair postorder(struct TreeNode *root, int n, int x)
{
	pair res = {0, false, false};
	if (!root)
		return res;
	pair l = postorder(root->left, n, x);
	if (l.flag)
		return l;
	pair r = postorder(root->right, n, x);
	if (r.flag)
		return r;
	res.nodecount = 1 + r.nodecount + l.nodecount;
	if (root->val == x)
	{
		int y = max(n - res.nodecount, max(l.nodecount, r.nodecount));
		res.result = 2 * y > n;
		res.flag = true;
	}
	return res;
}

bool btreeGameWinningMove(struct TreeNode *root, int n, int x)
{
	return postorder(root, n, x).result;
}
