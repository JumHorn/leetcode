#include <queue>
#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
public:
	int val;
	vector<Node *> children;

	Node() {}

	Node(int _val)
	{
		val = _val;
	}

	Node(int _val, vector<Node *> _children)
	{
		val = _val;
		children = _children;
	}
};

class Solution
{
public:
	vector<vector<int>> levelOrder(Node *root)
	{
		vector<vector<int>> res;
		if (root == nullptr)
			return res;
		queue<Node *> q;
		q.push(root);
		while (!q.empty())
		{
			res.push_back({});
			int size = q.size();
			while (--size >= 0)
			{
				auto node = q.front();
				q.pop();
				res.back().push_back(node->val);
				for (auto child : node->children)
					q.push(child);
			}
		}
		return res;
	}
};