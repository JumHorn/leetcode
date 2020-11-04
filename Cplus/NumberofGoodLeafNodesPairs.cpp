#include <vector>
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

class Solution
{
public:
	int countPairs(TreeNode *root, int distance)
	{
		int count = 0;
		postorder(root, distance, count);
		return count;
	}

	//return type {distance of node count}
	const vector<int> postorder(TreeNode *root, int distance, int &count)
	{
		if (root == nullptr)
			return vector<int>(distance + 1);
		if (root->left == nullptr && root->right == nullptr)
		{
			vector<int> res(distance + 1);
			res[1] = 1;
			return res;
		}
		auto &l = postorder(root->left, distance, count);
		auto &r = postorder(root->right, distance, count);
		for (int i = 1; i <= distance; ++i)
		{
			for (int j = 1; j <= distance; ++j)
			{
				if (i + j <= distance)
					count += l[i] * r[j];
			}
		}
		vector<int> res(distance + 1);
		for (int i = 1; i < distance; ++i)
			res[i + 1] = l[i] + r[i];
		return res;
	}
};