#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	TreeNode *recoverFromPreorder(string S)
	{
		int index = 0;
		return preorder(S, index, 0);
	}

	int strToInt(string &S, int &index)
	{
		int res = 0;
		while (index < (int)S.length() && S[index] != '-')
		{
			res = res * 10 + S[index] - '0';
			++index;
		}
		return res;
	}

	TreeNode *preorder(string &S, int &index, int layer)
	{
		int depth = index;
		while (depth < (int)S.length() && S[depth] == '-')
			++depth;
		depth -= index;
		if (depth != layer)
			return NULL;
		index += depth;
		TreeNode *node = new TreeNode(strToInt(S, index));
		node->left = preorder(S, index, layer + 1);
		node->right = preorder(S, index, layer + 1);
		return node;
	}
};