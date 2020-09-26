#include <stdlib.h>
#include <string.h>

//prefix tree
typedef struct Trie
{
	int count; //number of words end with this node
	struct Trie *nodes[2];
} Trie;

Trie *createNode()
{
	Trie *node = (Trie *)malloc(sizeof(Trie));
	memset(node, 0, sizeof(Trie));
	return node;
}

void insert(Trie *root, int num)
{
	for (int i = 31; i >= 0; --i)
	{
		int index = ((num >> i) & 1);
		if (!root->nodes[index])
			root->nodes[index] = createNode();
		root = root->nodes[index];
	}
	++root->count;
}

int search(Trie *root, int num)
{
	int res = 0;
	for (int i = 31; i >= 0; i--)
	{
		int index = ((num >> i) & 1);
		if (root->nodes[index ^ 1])
		{
			res |= 1 << i;
			root = root->nodes[index ^ 1];
		}
		else
			root = root->nodes[index];
	}
	return res;
}
/********end of prefix tree********/

int findMaximumXOR(int *nums, int numsSize)
{
	Trie *root = createNode();
	for (int i = 0; i < numsSize; ++i)
		insert(root, nums[i]);
	int res = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		int val = search(root, nums[i]);
		if (res < val)
			res = val;
	}
	return res;
}