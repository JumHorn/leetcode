#include <algorithm>
#include <unordered_map>
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
	vector<int> resultArray(vector<int> &nums)
	{
		vector<int> dup = nums;
		sort(dup.begin(), dup.end());
		unordered_map<int, int> index;
		for (auto n : dup)
			index.insert({n, index.size()});
		int N = nums.size(), len0 = 1, len1 = 1;
		Fenwick bit0(N), bit1(N);
		vector<int> arr0 = {nums[0]}, arr1 = {nums[1]};
		bit0.update(index[nums[0]], 1);
		bit1.update(index[nums[1]], 1);
		for (int j = 2; j < N; ++j)
		{
			int n = nums[j];
			int i = index[n];
			int g0 = len0 - bit0.sum(i);
			int g1 = len1 - bit1.sum(i);
			if (g0 > g1)
			{
				bit0.update(i, 1);
				++len0;
				arr0.push_back(n);
			}
			else if (g0 < g1)
			{
				bit1.update(i, 1);
				++len1;
				arr1.push_back(n);
			}
			else
			{
				if (len1 < len0)
				{
					bit1.update(i, 1);
					++len1;
					arr1.push_back(n);
				}
				else
				{
					bit0.update(i, 1);
					++len0;
					arr0.push_back(n);
				}
			}
		}

		for (auto n : arr1)
			arr0.push_back(n);
		return arr0;
	}
};