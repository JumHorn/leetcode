#include <vector>
using namespace std;

class Solution
{
public:
	vector<long long> maximumEvenSplit(long long finalSum)
	{
		long long cur = 2;
		if (finalSum % 2 != 0)
			return {};
		vector<long long> res;
		for (; finalSum > 2 * cur; finalSum -= cur, cur += 2)
			res.push_back(cur);
		if (finalSum != 0)
			res.push_back(finalSum);
		return res;
	}
};