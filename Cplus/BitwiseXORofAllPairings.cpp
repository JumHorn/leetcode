#include <vector>
using namespace std;

class Solution
{
public:
	int xorAllNums(vector<int> &nums1, vector<int> &nums2)
	{
		vector<long> count1(31), count2(31);
		long N1 = nums1.size(), N2 = nums2.size();
		for (auto n : nums1)
		{
			for (int i = 0; i < 31; ++i)
			{
				if ((n >> i) & 1)
					++count1[i];
			}
		}
		for (auto n : nums2)
		{
			for (int i = 0; i < 31; ++i)
			{
				if ((n >> i) & 1)
					++count2[i];
			}
		}
		int res = 0;
		for (int i = 0; i < 31; ++i)
		{
			int bit = (count1[i] * (N2 - count2[i]) + count2[i] * (N1 - count1[i])) % 2;
			res |= bit << i;
		}
		return res;
	}
};