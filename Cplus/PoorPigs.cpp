#include <cmath>
using namespace std;

class Solution
{
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest)
	{
		int k = minutesToTest / minutesToDie;
		if (k == 0)
			return -1;
		return ceil(log(buckets) / log(k + 1));
	}
};