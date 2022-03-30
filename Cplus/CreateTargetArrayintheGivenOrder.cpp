#include <set>
#include <vector>
using namespace std;

//Fenwick tree(BIT)
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
	vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
	{
		int N = index.size();
		Fenwick bit(N + 1);
		for (auto n : index)
			bit.update(n, 1);
		// this O(n^2) part can be optimized using BIT to O(nlogn)
		// for (int i = 0; i < indexSize; ++i)
		// {
		// 	for (int j = i + 1; j < indexSize; ++j)
		// 	{
		// 		if (index[i] >= index[j])
		// 			++index[i];
		// 	}
		// }
		for (int i = 0; i < N; ++i)
		{
			bit.update(index[i], -1);
			index[i] += bit.sum(index[i]);
		}
		vector<int> res(N);
		for (int i = 0; i < N; ++i)
			res[index[i]] = nums[i];
		return res;
	}
};