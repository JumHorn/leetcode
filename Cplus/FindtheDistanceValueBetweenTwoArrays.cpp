#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
	{
		sort(arr2.begin(), arr2.end());
		int res = 0;
		for (auto n : arr1)
		{
			auto iter = upper_bound(arr2.begin(), arr2.end(), n);
			if (iter != arr2.end())
			{
				if (abs(*iter - n) <= d)
					continue;
			}
			if (iter != arr2.begin())
				--iter;
			if (abs(*iter - n) > d)
				++res;
		}
		return res;
	}
};