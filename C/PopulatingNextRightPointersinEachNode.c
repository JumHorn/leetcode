
//Definition for a Node.
struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
	struct Node *next;
};

struct Node *connect(struct Node *root)
{
	if (!root)
		return root;
	if (root->left)
		root->left->next = root->right;
	if (root->right && root->next)
		root->right->next = root->next->left;
	connect(root->left);
	connect(root->right);
	return root;
}
