#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numIdenticalPairs(vector<int> &nums)
	{
		unordered_map<int, int> m; //{value,count}
		for (auto n : nums)
			++m[n];
		int res = 0;
		for (auto &n : m)
			res += n.second * (n.second - 1) / 2;
		return res;
	}
};