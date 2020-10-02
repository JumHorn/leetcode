#include <algorithm>
#include <vector>
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
	int widthOfBinaryTree(TreeNode *root)
	{
		vector<int> layer; //each layer's left most index
		int res = 0;
		preorder(root, 0, 0, layer, res);
		return res;
	}

	void preorder(TreeNode *root, int height, unsigned long long index, vector<int> &layer, int &width)
	{
		if (root == nullptr)
			return;
		if (height >= (int)layer.size())
			layer.push_back(index);
		width = max((unsigned long long)width, index - layer[height] + 1);
		preorder(root->left, height + 1, index * 2, layer, width);
		preorder(root->right, height + 1, index * 2 + 1, layer, width);
	}
};