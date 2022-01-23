#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfArrays(vector<int> &differences, int lower, int upper)
	{
		vector<long> seq = {0};
		for (auto n : differences)
			seq.push_back(n + seq.back());
		long minval = *min_element(seq.begin(), seq.end());
		long diff = lower - minval;
		long maxval = *max_element(seq.begin(), seq.end());
		maxval += diff;
		return max(0L, upper - maxval + 1);
	}
};