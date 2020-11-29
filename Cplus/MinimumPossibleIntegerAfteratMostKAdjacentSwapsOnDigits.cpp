#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
So we need a data structure to store the indexes of picked numbers,
to support fast calculation of the new index of each remaining number.
BIT, Segment Tree and Balanced Binary Search Tree can do this.
we can make use of sortedcontainers
*/

/*
BIT

original string: "1 2 4 0 5 6 7", original k = 3;
use/not state:    1 1 1 0 1 1 1 (1: not been used, 0: used);
prefix sum:       1 2 3 3 4 5 6 real index = prefixsum + used

original string: "1 4 2 5 6 7", k = 2;
use/not state:    0 1 0 1 1 1 (1: not been used, 0: used);
prefix sum:       0 1 1 2 3 4
*/

//Fenwick tree
class Fenwick
{
public:
	Fenwick(int size) : tree(size + 1) {}

	int sum(int index) const
	{
		int res = 0;
		++index;
		while (index > 0)
		{
			res += tree[index];
			index -= index & -index;
		}
		return res;
	}

	void update(int index, int delta)
	{
		++index;
		int size = tree.size();
		while (index < size)
		{
			tree[index] += delta;
			index += index & -index;
		}
	}

private:
	vector<int> tree;
};

class Solution
{
public:
	string minInteger(string num, int k)
	{
		int N = num.length();
		if (k >= N * (N - 1) / 2)
		{
			sort(num.begin(), num.end());
			return num;
		}
		Fenwick bit(N);
		for (int i = 0; i < N; ++i)
			bit.update(i, 1);
		vector<vector<int>> count(10);
		for (int i = N - 1; i >= 0; --i)
			count[num[i] - '0'].push_back(i);
		string res;
		vector<int> seen(N);
		bool flag = true;
		for (int c = k; c > 0 && flag;)
		{
			flag = false;
			for (int i = 0; i < 10; ++i)
			{
				if (!count[i].empty())
				{
					flag = true;
					int index = count[i].back();
					int move = bit.sum(index) - 1;
					if (c < move)
						continue;
					seen[index] = 1;
					res.push_back(i + '0');
					c -= move;
					bit.update(index, -1);
					count[i].pop_back();
					break;
				}
			}
		}
		for (int i = 0; i < N; ++i)
		{
			if (seen[i] == 0)
				res.push_back(num[i]);
		}
		return res;
	}
};