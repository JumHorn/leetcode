#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	long long continuousSubarrays(vector<int> &nums)
	{
		long long res = 0, N = nums.size();
		multiset<int> s;
		for (int i = 0, j = 0; i < N; ++i)
		{
			s.insert(nums[i]);
			for (;; ++j)
			{
				int minval = *s.begin();
				int maxval = *s.rbegin();
				if (maxval - minval <= 2)
					break;
				s.erase(s.find(nums[j]));
			}
			res += i - j + 1;
		}
		return res;
	}
};