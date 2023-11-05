#include <algorithm>
#include <climits>
#include <map>
#include <vector>
using namespace std;

// Fenwick tree(BIT)
class Fenwick
{
public:
	Fenwick(int size) : tree(size + 1) {}

	long long sum(int index) const
	{
		long long res = LLONG_MIN;
		for (++index; index > 0; index -= index & -index)
			res = max(res, tree[index]);
		return res;
	}

	void update(int index, long long val)
	{
		int N = tree.size();
		for (++index; index < N; index += index & -index)
			tree[index] = max(tree[index], val);
	}

private:
	vector<long long> tree;
};
/********end of Fenwick tree(BIT)********/

class Solution
{
public:
	long long maxBalancedSubsequenceSum(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> b;
		for (int i = 0; i < N; ++i)
			b.push_back(nums[i] - i);
		sort(b.begin(), b.end());
		map<int, int> m; //{nums[i]-i,new index}
		int index = -1;
		m[b[0]] = ++index;
		// remove dumplicate
		for (int i = 1, j = 0; i < N; ++i)
		{
			if (b[i] != b[j])
			{
				m[b[i]] = ++index;
				j = i;
			}
		}

		long long res = LLONG_MIN;
		Fenwick bit(m.size());
		for (int i = 0; i < N; ++i)
		{
			index = m[nums[i] - i];
			long long maxsum = bit.sum(index) + nums[i];
			res = max(res, maxsum);
			bit.update(index, maxsum);
		}
		return res;
	}
};