#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool preorder(struct ListNode *head, struct TreeNode *root)
{
	if (!head)
		return true;
	if (!root)
		return false;
	if (head->val != root->val)
		return false;
	return preorder(head->next, root->left) || preorder(head->next, root->right);
}

bool isSubPath(struct ListNode *head, struct TreeNode *root)
{
	if (!head)
		return true;
	if (!root)
		return false;
	return preorder(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}