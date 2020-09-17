#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
	struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	node->left = node->right = NULL;
	node->val = val;
	return node;
}

struct ListNode *getMiddle(struct ListNode *head, struct ListNode *tail)
{
	if (head == tail)
		return head;
	struct ListNode *walker = head, *runner = head->next;
	while (runner != tail && runner->next != tail)
	{
		runner = runner->next->next;
		walker = walker->next;
	}
	return walker;
}

struct TreeNode *preorder(struct ListNode *head, struct ListNode *tail)
{
	if (head == tail)
		return NULL;
	struct ListNode *mi = getMiddle(head, tail);
	struct TreeNode *root = createNode(mi->val);
	root->left = preorder(head, mi);
	root->right = preorder(mi->next, tail);
	return root;
}

struct TreeNode *sortedListToBST(struct ListNode *head)
{
	return preorder(head, NULL);
}