#include <vector>
using namespace std;

class Solution
{
public:
	bool canChoose(vector<vector<int>> &groups, vector<int> &nums)
	{
		int i = 0, N = nums.size();
		for (auto &group : groups)
		{
			int size = group.size(), j = i;
			for (; i < N; ++i)
			{
				for (j = i; j - i < size && j < N; ++j)
				{
					if (nums[j] != group[j - i])
						break;
				}
				if (j - i == size)
					break;
			}
			if (i >= N)
				return false;
			i = j;
		}
		return true;
	}
};