#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int majorityElement(vector<int> &nums)
	{
		int N = nums.size();
		unordered_map<int, int> m;
		for (auto n : nums)
		{
			if (++m[n] * 2 > N)
				return n;
		}
		return 0;
	}
};