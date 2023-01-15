#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countGood(vector<int> &nums, int k)
	{
		long long res = 0, N = nums.size(), p = 0;
		unordered_map<int, int> m; //{val,count}
		for (int i = 0, j = 0; j <= N;)
		{
			if (j == N || p >= k)
			{
				if (p < k)
					break;
				res += N - j + 1;
				p -= --m[nums[i]];
				++i;
			}
			else
			{
				p += m[nums[j]]++;
				++j;
			}
		}
		return res;
	}
};