#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int findTargetSumWays(vector<int> &nums, int S)
	{
		unordered_map<int, int> hash, next_hash; //{value,count}
		hash[0] = 1;
		for (auto n : nums)
		{
			next_hash.clear();
			for (auto m : hash)
			{
				next_hash[m.first + n] += m.second;
				next_hash[m.first - n] += m.second;
			}
			hash.swap(next_hash);
		}
		return hash[S];
	}
};