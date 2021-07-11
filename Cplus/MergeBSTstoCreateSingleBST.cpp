#include <unordered_map>
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
	TreeNode *canMerge(vector<TreeNode *> &trees)
	{
		unordered_map<int, TreeNode *> roots;	//{val,root}
		unordered_map<int, TreeNode **> leaves; //{val,leaf}
		int node = 0;
		for (auto t : trees)
		{
			roots[t->val] = t;
			++node;
			// to avoid only one node as root not leaf
			node += preorder(t->left, leaves);
			node += preorder(t->right, leaves);
		}

		// find root
		TreeNode *root = nullptr;
		for (auto [val, r] : roots)
		{
			if (leaves.find(val) == leaves.end())
			{
				root = r;
				break;
			}
		}
		if (root == nullptr)
			return nullptr;
		for (auto [val, r] : roots)
		{
			if (root == r)
				continue;
			if (leaves.find(val) == leaves.end())
				return nullptr;
			*leaves[val] = r;
			--node;
		}
		int pre = -1;
		return isValidBST(root, pre) && nodeCount(root) == node ? root : nullptr;
	}

	int nodeCount(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		return 1 + nodeCount(root->left) + nodeCount(root->right);
	}

	// check isvalid tree
	bool isValidBST(TreeNode *root, int &pre)
	{
		if (root == nullptr)
			return true;
		if (!isValidBST(root->left, pre))
			return false;
		if (pre >= root->val)
			return false;
		pre = root->val;
		return isValidBST(root->right, pre);
	}

	// store leaf node and return node count
	int preorder(TreeNode *&root, unordered_map<int, TreeNode **> &leaves)
	{
		if (root == nullptr)
			return 0;
		int res = 1;
		if (root->left == nullptr && root->right == nullptr)
			leaves[root->val] = &root;
		res += preorder(root->left, leaves);
		res += preorder(root->right, leaves);
		return res;
	}
};