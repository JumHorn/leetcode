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
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
	{
		vector<int> v1, v2;
		preorder(root1, v1);
		preorder(root2, v2);
		vector<int> res(v1.size() + v2.size());
		int i = 0, j = 0, index = 0;
		while (i < (int)v1.size() && j < (int)v2.size())
		{
			if (v1[i] <= v2[j])
				res[index++] = v1[i++];
			else
				res[index++] = v2[j++];
		}
		while (i < (int)v1.size())
			res[index++] = v1[i++];
		while (j < (int)v2.size())
			res[index++] = v2[j++];
		return res;
	}

	void preorder(TreeNode* root, vector<int>& v)
	{
		if (!root)
			return;
		preorder(root->left, v);
		v.push_back(root->val);
		preorder(root->right, v);
	}
};
