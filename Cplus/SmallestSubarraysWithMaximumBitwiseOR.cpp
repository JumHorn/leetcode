#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> smallestSubarrays(vector<int> &nums)
	{
		int N = nums.size();
		vector<vector<int>> pos(N, vector<int>(30));
		for (int i = 0; i < 30; ++i)
		{
			int last = N - 1;
			for (int j = N - 1; j >= 0; --j)
			{
				if (nums[j] & (1 << i))
					last = j;
				pos[j][i] = last + 1 - j;
			}
		}

		vector<int> maxall(N + 1);
		for (int i = N - 1; i >= 0; --i)
			maxall[i] = (maxall[i + 1] | nums[i]);

		vector<int> res(N);
		for (int i = 0; i < N; ++i)
		{
			int val = 0;
			for (int j = 0; j < 30; ++j)
			{
				if ((1 << j) & maxall[i])
					val = max(val, pos[i][j]);
			}
			res[i] = max(1, val);
		}
		return res;
	}
};