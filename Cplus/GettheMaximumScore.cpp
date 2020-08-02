#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSum(vector<int>& nums1, vector<int>& nums2)
	{
		int N1 = nums1.size(), N2 = nums2.size();
		vector<vector<long>> dp(2, vector<long>(max(N1, N2), -1));
		unordered_map<int, pair<int, int>> m;  //{val,{index1,index2}}
		for (int i = 0, j = 0; i < N1 && j < N2;)
		{
			if (nums1[i] == nums2[j])
				m[nums1[i]] = {i, j};
			nums1[i] < nums2[j] ? ++i : ++j;
		}
		return max(memdp(nums1, nums2, 0, 0, m, dp), memdp(nums1, nums2, 1, 0, m, dp)) % MOD;
	}

	long memdp(vector<int>& nums1, vector<int>& nums2, int turn, int index, unordered_map<int, pair<int, int>>& path, vector<vector<long>>& dp)
	{
		if (turn == 0)
		{
			if (index >= (int)nums1.size())
				return 0;
		}
		else
		{
			if (index >= (int)nums2.size())
				return 0;
		}
		if (dp[turn][index] != -1)
			return dp[turn][index];
		long res = 0;
		int val = (turn == 0 ? nums1[index] : nums2[index]);
		res += val;
		if (path.find(val) == path.end())
			res += memdp(nums1, nums2, turn, index + 1, path, dp);
		else
		{
			int newindex = (turn == 0 ? path[val].second : path[val].first);
			res += max(memdp(nums1, nums2, turn, index + 1, path, dp), memdp(nums1, nums2, 1 - turn, newindex + 1, path, dp));
		}
		return dp[turn][index] = res;
	}

private:
	static const int MOD = 1e9 + 7;
};
