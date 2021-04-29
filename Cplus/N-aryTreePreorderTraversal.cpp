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
	vector<int> preorder(Node *root)
	{
		vector<int> res;
		preorder(root, res);
		return res;
	}

	void preorder(Node *root, vector<int> &res)
	{
		if (root == nullptr)
			return;
		res.push_back(root->val);
		for (int i = 0; i < (int)root->children.size(); ++i)
			preorder(root->children[i], res);
	}
};