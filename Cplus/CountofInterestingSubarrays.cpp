#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countInterestingSubarrays(vector<int> &nums, int modulo, int k)
	{
		unordered_map<int, int> m; //{modulo,cnt}
		long long res = 0, cnt = 0;
		m[0] = 1;
		for (auto n : nums)
		{
			if (n % modulo == k)
				cnt = (cnt + 1) % modulo;
			res += m[(cnt - k + modulo) % modulo];
			++m[cnt];
		}
		return res;
	}
};