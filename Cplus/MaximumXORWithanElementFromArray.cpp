#include <algorithm>
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
		for (int i = 31; i >= 0; --i)
		{
			int index = ((num >> i) & 1);
			if (!node->nodes[index])
				node->nodes[index] = new TreeNode();
			node = node->nodes[index];
		}
		++node->count;
	}

	int search(int num) const
	{
		TreeNode *node = root;
		int res = 0;
		for (int i = 31; i >= 0; --i)
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
	vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
	{
		int N = queries.size();
		for (int i = 0; i < N; ++i)
			queries[i].push_back(i);
		sort(queries.begin(), queries.end(), *this);
		sort(nums.begin(), nums.end());
		vector<int> res(N);
		Trie trie;
		for (int i = 0, j = 0; i < N; ++i)
		{
			for (; j < N && nums[j] <= queries[i][1]; ++j)
				trie.insert(nums[j]);
			if (j == 0)
				res[queries[i][2]] = -1;
			else
				res[queries[i][2]] = trie.search(queries[i][0]);
		}
		return res;
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		return lhs[1] < rhs[1];
	}
};