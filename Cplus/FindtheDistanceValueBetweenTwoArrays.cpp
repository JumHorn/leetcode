#include <cmath>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
	{
		set<int> s(arr2.begin(), arr2.end());
		int res = 0;
		for (auto n : arr1)
		{
			auto iter = s.upper_bound(n);
			if (iter != s.end())
				if (abs(*iter - n) <= d)
					continue;
			if (iter != s.begin())
				--iter;
			if (abs(*iter - n) > d)
				res++;
		}
		return res;
	}
};
