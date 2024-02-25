#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
	{
		int N = nums.size(), M = changeIndices.size();
		int lo = 0, hi = M + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (!canDo(nums, changeIndices, mi))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo == M + 1 ? -1 : lo;
	}

	bool canDo(vector<int> &nums, vector<int> &changeIndices, int size)
	{
		unordered_map<int, int> m; //{val,last pos}
		for (int i = 0; i < size; ++i)
			m[changeIndices[i]] = i;
		if (m.size() != nums.size())
			return false;
		int op = 0; // operations wait to complete
		for (int i = 0; i < size; ++i)
		{
			if (m[changeIndices[i]] == i)
			{
				if (op < nums[changeIndices[i] - 1])
					return false;
				op -= nums[changeIndices[i] - 1];
			}
			else
				++op;
		}
		return true;
	}
};