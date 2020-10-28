#include <stack>
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

class BSTIterator
{
public:
	BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward)
	{
	}

	bool hasNext()
	{
		return node != nullptr || !s.empty();
	}

	int next()
	{
		while (node || !s.empty())
		{
			if (node)
			{
				s.push(node);
				node = forward ? node->left : node->right;
			}
			else
			{
				node = s.top();
				s.pop();
				int val = node->val;
				node = forward ? node->right : node->left;
				return val;
			}
		}
		return -1; // never reach & not necessary
	}

private:
	stack<TreeNode *> s;
	TreeNode *node;
	bool forward;
};

class Solution
{
public:
	bool findTarget(TreeNode *root, int k)
	{
		if (!root)
			return false;
		BSTIterator forward(root, true);
		BSTIterator backward(root, false);
		for (int i = forward.next(), j = backward.next(); i < j;)
		{
			int sum = i + j;
			if (sum == k)
				return true;
			sum < k ? i = forward.next() : j = backward.next();
		}
		return false;
	}
};