#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class SegmentTree
{
public:
	SegmentTree(int n) : data(2 * n)
	{
	}

	SegmentTree(vector<int> &v) : data(2 * v.size())
	{
	}

	void update(int index, int val)
	{
		int n = data.size() / 2;
		for (index += n; index > 0; index >>= 1)
			data[index] = max(data[index], val);
	}

	//[start,end) query range start included and end not included
	int queryRange(int start, int end)
	{
		int n = data.size() / 2, res = 0;
		for (int l = start + n, r = end + n; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1)
				res = max(res, data[l++]);
			if (r & 1)
				res = max(res, data[--r]);
		}
		return res;
	}

private:
	vector<int> data; //tree data with 0 index reserved
};

class Solution
{
public:
	int lengthOfLIS(vector<int> &nums, int k)
	{
		vector<int> dup = nums;
		sort(dup.begin(), dup.end());
		map<int, int> m;
		int rank = -1, pre = -1;
		for (auto n : dup)
		{
			if (pre != n)
				m[n] = ++rank;
			pre = n;
		}

		int N = nums.size();
		SegmentTree tree(N);
		for (auto n : nums)
		{
			rank = m[n];
			auto it = m.lower_bound(n - k);
			int lower = (it == m.end() ? 0 : it->second);
			int longest = tree.queryRange(lower, rank) + 1;
			tree.update(rank, longest);
		}
		return tree.queryRange(0, N);
	}
};