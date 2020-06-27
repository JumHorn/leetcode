#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	double average(vector<int>& salary)
	{
		int maxval = INT_MIN, minval = INT_MAX;
		int sum = 0;
		for (auto n : salary)
		{
			sum += n;
			if (n > maxval)
				maxval = n;
			if (n < minval)
				minval = n;
		}
		return (sum - maxval - minval) * 1.0 / (salary.size() - 2);
	}
};
