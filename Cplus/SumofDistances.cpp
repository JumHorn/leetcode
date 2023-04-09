#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<long long> distance(vector<int> &nums)
	{
		unordered_map<int, long long> m1; //{val,sum}
		unordered_map<int, long long> m2; //{val,count}
		int N = nums.size();
		vector<long long> res(N);
		for (long long i = 0; i < N; ++i)
		{
			res[i] += m2[nums[i]] * i - m1[nums[i]];
			m1[nums[i]] += i;
			++m2[nums[i]];
		}
		m1.clear();
		m2.clear();
		for (long long i = N - 1; i >= 0; --i)
		{
			res[i] += m1[nums[i]] - m2[nums[i]] * i;
			m1[nums[i]] += i;
			++m2[nums[i]];
		}
		return res;
	}
};