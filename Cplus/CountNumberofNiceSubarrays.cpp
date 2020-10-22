#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfSubarrays(vector<int> &nums, int k)
	{
		int res = 0, odd = 0;
		unordered_map<int, int> m; //{odd value,count}
		m[0] = 1;
		for (auto n : nums)
		{
			odd += n % 2;
			res += m[odd - k];
			++m[odd];
		}
		return res;
	}
};