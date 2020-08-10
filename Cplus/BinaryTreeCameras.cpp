#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//0 leaf node not covered
//1 the parent of leaf covered
//2 covered and parent of this node is leaf
class Solution
{
public:
	int minCameraCover(TreeNode *root)
	{
		auto res = postorder(root);
		return res.second + (res.first == 0 ? 1 : 0);
	}

	pair<int, int> postorder(TreeNode *root) //return {nodetype,result count}
	{
		if (root == NULL)
			return {2, 0};
		auto l = postorder(root->left), r = postorder(root->right);
		int res = l.second + r.second;
		if (l.first == 0 || r.first == 0)
			return {1, res + 1};
		return (l.first == 1 || r.first == 1) ? pair<int, int>(2, res) : pair<int, int>(0, res);
	}
};