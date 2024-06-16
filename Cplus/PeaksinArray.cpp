#include <vector>
using namespace std;

// Fenwick tree(BIT)
class Fenwick
{
public:
	Fenwick(int size) : tree(size + 1) {}

	int sum(int index) const
	{
		int res = 0;
		for (++index; index > 0; index -= index & -index)
			res += tree[index];
		return res;
	}

	void update(int index, int delta)
	{
		int N = tree.size();
		for (++index; index < N; index += index & -index)
			tree[index] += delta;
	}

private:
	vector<int> tree;
};
/********end of Fenwick tree(BIT)********/

class Solution
{
public:
	vector<int> countOfPeaks(vector<int> &nums, vector<vector<int>> &queries)
	{
		int N = nums.size();
		Fenwick bit(N);
		for (int i = 1; i < N - 1; ++i)
		{
			if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
				bit.update(i, 1);
		}
		vector<int> res;
		for (auto &q : queries)
		{
			if (q[0] == 1)
			{
				if (q[2] == 0 || q[1] == q[2])
					res.push_back(0);
				else
					res.push_back(bit.sum(q[2] - 1) - bit.sum(q[1]));
			}
			else
			{
				int index = q[1], val = q[2];
				nums[index] = val;
				if (index > 0 && index < N - 1)
				{
					int old = bit.sum(index) - bit.sum(index - 1);
					int v = nums[index] > nums[index - 1] && nums[index] > nums[index + 1];
					bit.update(index, v - old);
				}
				if (index > 0)
				{
					--index;
					int old = bit.sum(index) - bit.sum(index - 1);
					int v = index == 0 ? 0 : (nums[index] > nums[index - 1] && nums[index] > nums[index + 1]);
					bit.update(index, v - old);
					++index;
				}
				if (index < N - 1)
				{
					++index;
					int old = bit.sum(index) - bit.sum(index - 1);
					int v = index == N - 1 ? 0 : (nums[index] > nums[index - 1] && nums[index] > nums[index + 1]);
					bit.update(index, v - old);
					--index;
				}
			}
		}
		return res;
	}
};