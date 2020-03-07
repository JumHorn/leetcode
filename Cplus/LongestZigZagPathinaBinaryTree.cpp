#include <algorithm>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	int longestZigZag(TreeNode* root)
	{
		int n = 0;
		traversal(root, n);
		vector<vector<int>> node(n, vector<int>(2));
		int res = 0;
		dfs(root, node, res);
		return res;
	}

	void traversal(TreeNode* root, int& n)
	{
		if (root == NULL)
			return;
		root->val = n++;
		traversal(root->left, n);
		traversal(root->right, n);
	}

	void dfs(TreeNode* root, vector<vector<int>>& node, int& res)
	{
		if (root == NULL)
			return;
		int left = dfs(root, node, true);	//left
		int right = dfs(root, node, false);  //right
		//cout<<left<<" "<<right<<endl;
		res = max(res, max(left, right));
		dfs(root->left, node, res);
		dfs(root->right, node, res);
	}

	int dfs(TreeNode* root, vector<vector<int>>& node, bool zig)
	{
		if (root == NULL)
			return 0;
		if (zig)
		{
			if (node[root->val][0] == 0)
				if (root->left != NULL)
					node[root->val][0] = 1 + dfs(root->left, node, !zig);
			return node[root->val][0];
		}
		else
		{
			if (node[root->val][1] == 0)
				if (root->right != NULL)
					node[root->val][1] = 1 + dfs(root->right, node, !zig);
			return node[root->val][1];
		}
	}
};
