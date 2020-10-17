#include <algorithm>
#include <map>
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
	vector<vector<int>> verticalTraversal(TreeNode *root)
	{
		vector<vector<int>> res;
		map<int, vector<pair<int, int>>> m; //{index,{layer,value}}
		preorder(root, 0, 0, m);
		for (auto &n : m)
		{
			res.push_back({});
			sort(n.second.begin(), n.second.end());
			for (auto x : n.second)
				res.back().push_back(x.second);
		}
		return res;
	}

	void preorder(TreeNode *root, int x, int y, map<int, vector<pair<int, int>>> &m)
	{
		if (root == nullptr)
			return;
		m[x].push_back({y, root->val});
		preorder(root->left, x - 1, y + 1, m);
		preorder(root->right, x + 1, y + 1, m);
	}
};