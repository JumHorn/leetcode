#include <stdio.h>
#include <string.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct string
{
	char data[50];
} string;

string preorder(struct TreeNode *root, string str)
{
	string data = {"~"};
	if (!root)
		return data;
	sprintf(data.data, "%c%s", root->val + 'a', str.data);
	if (root->left == root->right) //root->left == nullptr && root->right == nullptr
		return data;
	string l = preorder(root->left, data);
	string r = preorder(root->right, data);
	return strcmp(l.data, r.data) <= 0 ? l : r;
}

char *smallestFromLeaf(struct TreeNode *root)
{
	string str = {"\0"};
	return preorder(root, str).data;
}