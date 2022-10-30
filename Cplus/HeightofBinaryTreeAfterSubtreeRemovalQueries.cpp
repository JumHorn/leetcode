#include <queue>
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
	vector<int> treeQueries(TreeNode *root, vector<int> &queries)
	{
		//height for each node
		unordered_map<int, int> height;
		postorder(root, height);

		vector<vector<int>> depth;
		vector<pair<int, int>> layertop2depth; //{first depth val,second depth val}
		queue<TreeNode *> q;
		q.push(root);
		depth.emplace_back();
		depth.back().push_back(root->val);
		layertop2depth.push_back({root->val, -1});
		//bfs
		while (!q.empty())
		{
			depth.emplace_back();
			layertop2depth.push_back({-1, -1});
			int size = q.size();
			while (--size >= 0)
			{
				auto node = q.front();
				q.pop();
				if (node->left != nullptr)
				{
					q.push(node->left);
					depth.back().push_back(node->left->val);
					updateTop2(node->left->val, height, layertop2depth.back());
				}
				if (node->right != nullptr)
				{
					q.push(node->right);
					depth.back().push_back(node->right->val);
					updateTop2(node->right->val, height, layertop2depth.back());
				}
			}
		}

		unordered_map<int, vector<int>> m; //{val,index}
		int M = queries.size();
		for (int i = 0; i < M; ++i)
			m[queries[i]].push_back(i);
		vector<int> res(M);
		for (int i = 0; i < depth.size(); ++i) //层层删除
		{
			for (auto n : depth[i])
			{
				if (m.count(n) != 0)
				{
					if (depth[i].size() == 1)
						setValue(i - 1, res, m[n]);
					else
					{
						if (n == layertop2depth[i].first)
							setValue(height[layertop2depth[i].second] + i - 1, res, m[n]);
						else
							setValue(height[layertop2depth[i].first] + i - 1, res, m[n]);
					}
				}
			}
		}
		return res;
	}

	void setValue(int val, vector<int> &res, vector<int> &index)
	{
		for (auto n : index)
			res[n] = val;
	}

	void updateTop2(int val, unordered_map<int, int> &height, pair<int, int> &layer)
	{
		if (layer.first == -1 || height[val] > height[layer.first])
		{
			layer.second = layer.first;
			layer.first = val;
		}
		else if (layer.second == -1 || height[val] > height[layer.second])
			layer.second = val;
	}

	int postorder(TreeNode *root, unordered_map<int, int> &height)
	{
		if (root == nullptr)
			return 0;
		int l = postorder(root->left, height);
		int r = postorder(root->right, height);
		return height[root->val] = max(l, r) + 1;
	}
};