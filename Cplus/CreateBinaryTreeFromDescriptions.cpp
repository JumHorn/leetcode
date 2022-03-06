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
	TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
	{
		unordered_map<int, TreeNode *> m;
		unordered_map<int, int> indegree; //{val,degree}
		for (auto &v : descriptions)
		{
			int parent = v[0], child = v[1], left = v[2];
			if (m.count(parent) == 0)
				m[parent] = new TreeNode(parent);
			if (m.count(child) == 0)
				m[child] = new TreeNode(child);
			if (left == 1)
				m[parent]->left = m[child];
			else
				m[parent]->right = m[child];
			if (indegree.count(parent) == 0)
				++indegree[parent];
			indegree[child] += 2;
		}
		for (auto [r, d] : indegree)
		{
			if (d == 1)
				return m[r];
		}
		return nullptr;
	}
};