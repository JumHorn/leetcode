
//Definition for a Node.
struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
	struct Node *next;
};

struct Node *findNext(struct Node *root)
{
	if (!root)
		return root;
	if (root->left)
		return root->left;
	if (root->right)
		return root->right;
	return findNext(root->next);
}

struct Node *connect(struct Node *root)
{
	if (!root)
		return root;
	if (root->left)
	{
		if (root->right)
			root->left->next = root->right;
		else
			root->left->next = findNext(root->next);
	}
	if (root->right)
		root->right->next = findNext(root->next);
	connect(root->right);
	connect(root->left);
	return root;
}
