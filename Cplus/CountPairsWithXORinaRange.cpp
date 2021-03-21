#include <vector>
using namespace std;

//Trie
class Trie
{
	struct TreeNode
	{
		int count; //number of words ends with this node
		vector<TreeNode *> nodes;

		TreeNode() : count(0), nodes(2, nullptr) {}
	};

public:
	Trie()
	{
		root = new TreeNode();
	}

	void insert(int num)
	{
		TreeNode *node = root;
		for (int i = 15; i >= 0; --i)
		{
			int index = ((num >> i) & 1);
			if (!node->nodes[index])
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
			++node->count;
		}
	}

	int count(int num, int limit) const
	{
		TreeNode *node = root;
		int res = 0;
		for (int i = 15; i >= 0 && node; --i)
		{
			int index = ((num >> i) & 1);
			int bit = ((limit >> i) & 1);
			if (bit == 1)
			{
				if (node->nodes[index])
					res += node->nodes[index]->count;
				node = node->nodes[1 ^ index];
			}
			else
				node = node->nodes[index];
		}
		return res;
	}

private:
	TreeNode *root;
};
/********end of Trie********/

class Solution
{
public:
	int countPairs(vector<int> &nums, int low, int high)
	{
		int res = 0;
		Trie trie;
		for (auto n : nums)
		{
			res += trie.count(n, high + 1) - trie.count(n, low);
			trie.insert(n);
		}
		return res;
	}
};