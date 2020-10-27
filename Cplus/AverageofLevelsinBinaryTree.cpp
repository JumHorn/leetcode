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
	vector<double> averageOfLevels(TreeNode *root)
	{
		vector<pair<double, int>> data; //{sum of level,node count of level}
		preorder(root, 0, data);
		vector<double> res;
		for (auto &p : data)
			res.push_back(p.first / p.second);
		return res;
	}

	void preorder(TreeNode *root, int layer, vector<pair<double, int>> &data)
	{
		if (root == nullptr)
			return;
		if (layer >= (int)data.size())
			data.push_back({0, 0});
		data[layer].first += root->val;
		++data[layer].second;
		preorder(root->left, layer + 1, data);
		preorder(root->right, layer + 1, data);
	}
};