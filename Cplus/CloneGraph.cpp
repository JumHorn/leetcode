#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// Definition for a Node.
class Node
{
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors)
	{
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution
{
public:
	Node* cloneGraph(Node* node)
	{
		vector<Node*> v;
		unordered_map<Node*, int> index;
		unordered_set<Node*> visited;
		dfs(node, v, visited, index);
		vector<Node*> copyv(v.size());
		for (int i = 0; i < (int)copyv.size(); i++)
		{
			copyv[i] = new Node();
			copyv[i]->val = v[i]->val;
		}
		for (int i = 0; i < (int)v.size(); i++)
		{
			for (auto& n : v[i]->neighbors)
				copyv[i]->neighbors.push_back(copyv[index[n]]);
		}
		return copyv.front();
	}

	void dfs(Node* node, vector<Node*>& v, unordered_set<Node*>& visited, unordered_map<Node*, int>& index)
	{
		if (visited.find(node) != visited.end())
			return;
		visited.insert(node);
		if (index.find(node) == index.end())
		{
			v.push_back(node);
			index[node] = v.size() - 1;
		}
		for (auto n : node->neighbors)
		{
			if (visited.find(n) != visited.end())
				continue;
			if (index.find(n) == index.end())
			{
				v.push_back(n);
				index[n] = v.size() - 1;
			}
			dfs(n, v, visited, index);
		}
	}
};
