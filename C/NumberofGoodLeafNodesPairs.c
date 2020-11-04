#include <string.h>

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct vector
{
	int distance[11];
} vector;

//return type {distance of node count}
vector postorder(struct TreeNode *root, int distance, int *count)
{
	vector res;
	memset(res.distance, 0, sizeof(res.distance));
	if (!root)
		return res;
	if (!root->left && !root->right)
	{
		res.distance[1] = 1;
		return res;
	}
	vector l = postorder(root->left, distance, count);
	vector r = postorder(root->right, distance, count);
	for (int i = 1; i <= distance; ++i)
	{
		for (int j = 1; j <= distance; ++j)
		{
			if (i + j <= distance)
				*count += l.distance[i] * r.distance[j];
		}
	}
	for (int i = 1; i < distance; ++i)
		res.distance[i + 1] = l.distance[i] + r.distance[i];
	return res;
}

int countPairs(struct TreeNode *root, int distance)
{
	int count = 0;
	postorder(root, distance, &count);
	return count;
}
