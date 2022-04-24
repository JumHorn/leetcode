#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> intersection(vector<vector<int>> &nums)
	{
		vector<int> count(1001);
		for (auto &v : nums)
		{
			for (auto n : v)
				++count[n];
		}
		int N = nums.size();
		vector<int> res;
		for (int i = 0; i < 1001; ++i)
		{
			if (count[i] == N)
				res.push_back(i);
		}
		return res;
	}
};