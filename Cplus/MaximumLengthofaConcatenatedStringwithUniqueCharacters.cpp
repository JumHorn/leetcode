#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxLength(vector<string>& arr)
	{
		vector<int> bit(arr.size());
		for (int i = 0; i < (int)arr.size(); i++)
			for (int j = 0; j < (int)arr[i].size(); j++)
			{
				if (bit[i] & (1 << (arr[i][j] - 'a')))
				{
					bit[i] = 0;
					break;
				}
				bit[i] |= 1 << (arr[i][j] - 'a');
			}
		vector<unordered_set<int>> v(arr.size());
		v[0].insert(bit[0]);
		v[0].insert(0);
		for (int i = 1; i < (int)arr.size(); i++)
			for (int j = 0; j < i; j++)
			{
				for (auto n : v[j])
				{
					if ((n & bit[i]) == 0)
						v[i].insert(n | bit[i]);
				}
			}
		int res = 0;
		for (int i = 0; i < (int)v.size(); i++)
			for (auto n : v[i])
				res = max(res, bitCount(n));
		return res;
	}

	int bitCount(int x)
	{
		x -= ((x >> 1) & 0x55555555);
		x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
		x = (x + (x >> 4)) & 0x0F0F0F0F;
		x += x >> 8;
		x += x >> 16;
		return x & 0x3F;
	}
};
