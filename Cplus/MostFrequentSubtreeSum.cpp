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
	vector<int> findFrequentTreeSum(TreeNode *root)
	{
		unordered_map<int, int> m; //{value,freq}
		postorder(root, m);
		int freq = -1;
		for (auto n : m)
			freq = max(freq, n.second);
		vector<int> res;
		for (auto n : m)
		{
			if (n.second == freq)
				res.push_back(n.first);
		}
		return res;
	}

	int postorder(TreeNode *root, unordered_map<int, int> &m)
	{
		if (root == nullptr)
			return 0;
		int l = postorder(root->left, m);
		int r = postorder(root->right, m);
		++m[l + r + root->val];
		return l + r + root->val;
	}
};