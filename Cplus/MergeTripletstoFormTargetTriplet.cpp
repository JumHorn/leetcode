#include <vector>
using namespace std;

class Solution
{
public:
	bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
	{
		vector<int> res(3);
		for (auto &v : triplets)
		{
			if (v[0] <= target[0] && v[1] <= target[1] && v[2] <= target[2])
			{
				res[0] = max(res[0], v[0]);
				res[1] = max(res[1], v[1]);
				res[2] = max(res[2], v[2]);
			}
			if (res == target)
				return true;
		}
		return false;
	}
};