#include <algorithm>
#include <vector>
using namespace std;

// Trie
class Trie
{
	struct TreeNode
	{
		int count; // number of words ends with this node
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
		for (int i = 31; i >= 0; --i)
		{
			int index = ((num >> i) & 1);
			if (!node->nodes[index])
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
			++node->count;
		}
	}

	void remove(int num)
	{
		TreeNode *node = root;
		for (int i = 31; i >= 0 && node != nullptr; --i)
		{
			int index = ((num >> i) & 1);
			if (!node->nodes[index])
				break;
			if (--node->nodes[index]->count == 0)
				node->nodes[index] = nullptr; // memory leak
			node = node->nodes[index];
		}
	}

	int search(int num) const
	{
		TreeNode *node = root;
		int res = 0;
		for (int i = 31; i >= 0 && node != nullptr; --i)
		{
			int index = ((num >> i) & 1);
			if (node->nodes[1 - index])
			{
				res |= 1 << i;
				node = node->nodes[1 - index];
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
	int maximumStrongPairXor(vector<int> &nums)
	{
		sort(nums.begin(), nums.end(), greater<int>());
		Trie trie;
		trie.insert(nums[0]);
		int res = 0, N = nums.size();
		for (int i = 1, j = 0; i < N; ++i)
		{
			for (; nums[j] - nums[i] > nums[i]; ++j)
				trie.remove(nums[j]);
			res = max(res, trie.search(nums[i]));
			trie.insert(nums[i]);
		}
		return res;
	}
};