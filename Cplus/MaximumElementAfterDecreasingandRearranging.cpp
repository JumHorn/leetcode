#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
	{
		int res = 0;
		sort(arr.begin(), arr.end());
		for (auto n : arr)
		{
			if (n - res > 1)
				++res;
		}
		return res + (arr.front() == 1 ? 1 : 0);
	}
};