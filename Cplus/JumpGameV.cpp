#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxJumps(vector<int> &arr, int d)
	{
		int N = arr.size();
		vector<int> dp(N);
		for (int i = 0; i < N; ++i)
			memdp(arr, d, i, dp);
		int res = 1;
		for (int i = 0; i < N; ++i)
			res = max(res, dp[i]);
		return res;
	}

	void memdp(vector<int> &arr, int d, int index, vector<int> &dp)
	{
		int left = index - 1, right = index + 1, left_max = 0, right_max = 0, N = arr.size();
		if (dp[index] != 0)
			return;
		while (left >= max(0, index - d) && arr[left] < arr[index])
		{
			if (dp[left] == 0)
				memdp(arr, d, left, dp);
			left_max = max(left_max, dp[left]);
			--left;
		}
		while (right <= min(N - 1, index + d) && arr[right] < arr[index])
		{
			if (dp[right] == 0)
				memdp(arr, d, right, dp);
			right_max = max(right_max, dp[right]);
			++right;
		}
		dp[index] = 1 + max(left_max, right_max);
	}
};