#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxLength(vector<string> &arr)
	{
		int N = arr.size();
		vector<int> bit;
		for (auto &str : arr)
		{
			int mask = 0;
			for (auto c : str)
			{
				if (mask & (1 << (c - 'a')))
				{
					mask = 0;
					break;
				}
				mask |= 1 << (c - 'a');
			}
			bit.push_back(mask);
		}
		unordered_set<int> dp;
		dp.insert(0);
		dp.insert(bit[0]);
		for (int i = 1; i < N; ++i)
		{
			unordered_set<int> pre_dp = dp;
			for (auto n : pre_dp)
			{
				if ((n & bit[i]) == 0)
					dp.insert(n | bit[i]);
			}
		}
		int res = 0;
		for (auto n : dp)
			res = max(res, bitCount(n));
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		while (n != 0)
		{
			++res;
			n &= n - 1;
		}
		return res;
	}
};