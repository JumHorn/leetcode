#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPossibleToSplit(vector<int> &nums)
	{
		unordered_map<int, int> m;
		for (auto n : nums)
		{
			if (++m[n] >= 3)
				return false;
		}
		return true;
	}
};