#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSumOfLengths(vector<int> &arr, int target)
	{
		int N = arr.size(), sum = 0, res = N + 1, curMinLen = N + 1;
		vector<int> dp(N + 1, N + 1);
		unordered_map<int, int> m; //{prefix sum,index}
		m[0] = 0;
		for (int i = 0; i < N; ++i)
		{
			sum += arr[i];
			int diff = sum - target;
			auto it = m.find(diff);
			if (it != m.end())
			{
				curMinLen = min(curMinLen, i - it->second + 1);
				res = min(res, dp[it->second] + i - it->second + 1);
			}
			dp[i + 1] = curMinLen;
			m[sum] = i + 1;
		}
		return res > N ? -1 : res;
	}
};