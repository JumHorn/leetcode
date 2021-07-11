#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getConcatenation(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> res(N * 2);
		for (int i = 0; i < N; ++i)
		{
			res[i] = nums[i];
			res[i + N] = nums[i];
		}
		return res;
	}
};