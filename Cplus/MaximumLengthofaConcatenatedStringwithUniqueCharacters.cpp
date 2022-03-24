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
		int res = 0;
		for (int mask = (1 << N) - 1; mask > 0; --mask)
		{
			int allmask = 0;
			for (int i = 0; i < N; ++i)
			{
				if (((1 << i) & mask))
				{
					if (allmask & bit[i])
					{
						allmask = -1;
						break;
					}
					allmask |= bit[i];
				}
			}
			if (allmask != -1)
				res = max(res, bitCount(allmask));
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