#include <algorithm>
#include <set>
#include <unordered_map>
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
	int lengthOfLIS(vector<int> &nums)
	{
		int N = nums.size();
		set<int> s(nums.begin(), nums.end());
		unordered_map<int, int> m;
		int rank = 0;
		for (auto n : s)
			m[n] = rank++;

		SegmentTree tree(N);
		for (auto n : nums)
		{
			rank = m[n];
			int longest = tree.queryRange(0, rank) + 1;
			tree.update(rank, longest);
		}
		return tree.queryRange(0, N);
	}
};