#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string findDifferentBinaryString(vector<string> &nums)
	{
		int N = nums.size();
		vector<int> seen(1 << N);
		for (auto &str : nums)
		{
			int n = 0;
			for (auto c : str)
				n = ((n << 1) | c - '0');
			seen[n] = 1;
		}
		for (int mask = (1 << N) - 1; mask >= 0; --mask)
		{
			if (seen[mask] == 0)
				return toBinStr(mask, nums[0].size());
		}
		return "0";
	}

	string toBinStr(int mask, int len)
	{
		string res;
		for (int i = len - 1; i >= 0; --i)
			res.push_back('0' + ((mask >> i) & 1));
		return res;
	}
};