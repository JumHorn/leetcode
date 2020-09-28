#include <stdlib.h>

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

int postorder(struct TreeNode* root, int* data, int* datasize)
{
	if (!root)
		return 0;
	int l = postorder(root->left, data, datasize);
	int r = postorder(root->right, data, datasize);
	return data[(*datasize)++] = l + r + root->val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findFrequentTreeSum(struct TreeNode* root, int* returnSize)
{
	static int staticRes[10000], staticResSize;
	staticResSize = 0;
	*returnSize = 0;
	if (!root)
		return NULL;
	postorder(root, staticRes, &staticResSize);
	qsort(staticRes, staticResSize, sizeof(int), cmp);
	int freq[staticResSize][2], freqsize = 0;  //{val,freq}
	int maxfreq = 0;
	for (int i = 0, j = 0; i <= staticResSize; ++i)
	{
		if (i == staticResSize || staticRes[i] != staticRes[j])
		{
			freq[freqsize][0] = staticRes[j];
			freq[freqsize][1] = i - j;
			++freqsize;
			if (maxfreq < i - j)
			{
				maxfreq = i - j;
				*returnSize = 1;
			}
			else if (maxfreq == i - j)
				++*returnSize;
			j = i;
		}
	}
	int *res = (int*)malloc(sizeof(int) * (*returnSize)), resSize = 0;
	for (int i = 0; i < freqsize; ++i)
	{
		if (freq[i][1] == maxfreq)
			res[resSize++] = freq[i][0];
	}
	return res;
}
