#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getAverages(vector<int> &nums, int k)
	{
		int len = 2 * k + 1, i = 0, N = nums.size();
		if (len > N)
			return vector<int>(N, -1);
		vector<int> res(k, -1);
		long long sum = 0;
		for (; i < len; ++i)
			sum += nums[i];
		res.push_back(sum / len);
		for (; i < N; ++i)
		{
			sum = sum + nums[i] - nums[i - len];
			res.push_back(sum / len);
		}
		for (int i = 0; i < k; ++i)
			res.push_back(-1);
		return res;
	}
};