#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
public:
	int val;
	vector<Node *> neighbors;

	Node()
	{
		val = 0;
		neighbors = vector<Node *>();
	}

	Node(int _val)
	{
		val = _val;
		neighbors = vector<Node *>();
	}

	Node(int _val, vector<Node *> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution
{
public:
	Node *cloneGraph(Node *node)
	{
		if (node == nullptr)
			return nullptr;
		Node *copy = new Node(node->val);
		unordered_map<Node *, Node *> seen; //{origin node,copy node}
		seen[node] = copy;
		dfs(node, copy, seen);
		return copy;
	}

	void dfs(Node *node, Node *copy, unordered_map<Node *, Node *> &seen)
	{
		if (node == nullptr)
			return;
		copy->neighbors.resize(node->neighbors.size());
		for (int i = 0; i < (int)node->neighbors.size(); ++i)
		{
			auto n = node->neighbors[i];
			if (seen.find(n) == seen.end())
			{
				seen[n] = new Node(n->val);
				copy->neighbors[i] = seen[n];
				dfs(node->neighbors[i], copy->neighbors[i], seen);
			}
			else
				copy->neighbors[i] = seen[n];
		}
	}
};