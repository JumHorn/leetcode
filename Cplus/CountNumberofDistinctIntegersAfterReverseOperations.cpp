#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int countDistinctIntegers(vector<int> &nums)
	{
		unordered_set<int> s;
		for (auto n : nums)
		{
			s.insert(n);
			s.insert(reverse(n));
		}
		return s.size();
	}

	int reverse(int n)
	{
		int res = 0;
		for (; n > 0; n /= 10)
			res = res * 10 + n % 10;
		return res;
	}
};