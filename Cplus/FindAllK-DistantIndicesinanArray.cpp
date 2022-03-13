#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
	{
		int N = nums.size();
		vector<bool> seen(N);
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == key)
			{
				for (int j = 0; j <= k; ++j)
				{
					if (i + j < N)
						seen[i + j] = true;
					if (i - j >= 0)
						seen[i - j] = true;
				}
			}
		}
		vector<int> res;
		for (int i = 0; i < N; ++i)
		{
			if (seen[i])
				res.push_back(i);
		}
		return res;
	}
};