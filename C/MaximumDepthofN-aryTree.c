
// Definition for a Node.
struct Node
{
	int val;
	int numChildren;
	struct Node** children;
};

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxDepth(struct Node* root)
{
	if (!root)
		return 0;
	int res = 0;
	for (int i = 0; i < root->numChildren; ++i)
	{
		int depth = maxDepth(root->children[i]);
		res = max(res, depth);
	}
	return res + 1;
}
