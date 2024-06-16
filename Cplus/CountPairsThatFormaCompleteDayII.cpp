#include <vector>
using namespace std;

class Solution
{
public:
	long long countCompleteDayPairs(vector<int> &hours)
	{
		vector<int> count(24);
		long long res = 0;
		for (auto n : hours)
		{
			res += count[(24 - n % 24) % 24];
			++count[n % 24];
		}
		return res;
	}
};