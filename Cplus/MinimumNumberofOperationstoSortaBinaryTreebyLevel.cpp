#include <algorithm>
#include <queue>
#include <unordered_map>
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
	int minimumOperations(TreeNode *root)
	{
		int res = 0;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			vector<int> v;
			while (--size >= 0)
			{
				auto node = q.front();
				q.pop();
				if (node->left != nullptr)
				{
					q.push(node->left);
					v.push_back(node->left->val);
				}
				if (node->right != nullptr)
				{
					q.push(node->right);
					v.push_back(node->right->val);
				}
			}
			res += countSwap(v);
		}
		return res;
	}

	int countSwap(vector<int> &v)
	{
		unordered_map<int, int> m;
		int N = v.size();
		for (int i = 0; i < N; ++i)
			m[v[i]] = i;
		vector<int> dup = v;
		sort(v.begin(), v.end());
		int res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (dup[i] != v[i])
			{
				int index = m[v[i]];
				m[dup[i]] = index;
				swap(dup[i], dup[index]);
				++res;
			}
		}
		return res;
	}
};