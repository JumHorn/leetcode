#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> recoverArray(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size(), smallest = nums[0];
		for (auto n : nums)
		{
			int k = (n - smallest) / 2; //try each possible k
			if (k > 0 && smallest + k == n - k)
			{
				vector<int> res, seen(N);
				for (int i = 0, j = 0; j < N; ++i)
				{
					if (seen[i])
						continue;
					for (; j < N && !seen[i]; ++j)
					{
						if (nums[i] + 2 * k < nums[j])
						{
							j = N; //to jump outter for loop
							break;
						}
						if (nums[i] + 2 * k == nums[j])
						{
							seen[i] = seen[j] = true;
							res.push_back(nums[i] + k);
						}
					}
				}
				if (res.size() == N / 2)
					return res;
			}
		}
		return {};
	}
};