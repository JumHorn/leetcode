#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
	{
		auto f = [](vector<int> &lhs, vector<int> &rhs) {
			return lhs[1] > rhs[1];
		};
		sort(boxTypes.begin(), boxTypes.end(), f);
		int res = 0;
		for (auto &v : boxTypes)
		{
			if (truckSize < v[0])
			{
				res += truckSize * v[1];
				break;
			}
			res += v[0] * v[1];
			truckSize -= v[0];
		}
		return res;
	}
};