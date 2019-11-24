#include <map>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Value
{
	int val;
	int Y;
	Value(int v, int y) : val(v), Y(y) {}
};

class Solution
{
public:
	vector<vector<int>> verticalTraversal(TreeNode *root)
	{
		vector<vector<int>> res;
		map<int, vector<Value>> m;
		preorder(root, 0, 0, m);
		for (auto n : m)
		{
			res.push_back(vector<int>());
			sort(n.second.begin(), n.second.end(), *this);
			for (auto x : n.second)
				res.back().push_back(x.val);
		}
		return res;
	}

	void preorder(TreeNode *root, int x, int y, map<int, vector<Value>> &m)
	{
		if (root == NULL)
			return;
		m[x].push_back({root->val, y});
		preorder(root->left, x - 1, y + 1, m);
		preorder(root->right, x + 1, y + 1, m);
	}

	bool operator()(const Value &lhs, const Value &rhs)
	{
		if (lhs.Y != rhs.Y)
			return lhs.Y < rhs.Y;
		return lhs.val < rhs.val;
	}
};
