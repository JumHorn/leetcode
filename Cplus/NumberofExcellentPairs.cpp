#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countExcellentPairs(vector<int> &nums, int k)
	{
		unordered_set<int> s(nums.begin(), nums.end()); //remove duplicate
		vector<int> count(100);
		long long res = 0, N = s.size();
		for (auto n : s)
			++count[bitCount(n)];
		for (int i = 1; i < 100; ++i) //prefixsum
			count[i] += count[i - 1];
		for (auto n : s)
		{
			int bit = bitCount(n);
			if (k - bit - 1 < 0)
				res += N;
			else
				res += N - count[k - bit - 1];
		}
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};