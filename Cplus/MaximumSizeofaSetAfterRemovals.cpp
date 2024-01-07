#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumSetSize(vector<int> &nums1, vector<int> &nums2)
	{
		int N = nums1.size(), count1 = N / 2, count2 = N / 2;
		unordered_map<int, int> m1, m2;
		for (auto n : nums1)
		{
			if (++m1[n] == 2 && count1 > 0)
			{
				--count1;
				--m1[n];
			}
		}
		for (auto n : nums2)
		{
			if (++m2[n] == 2 && count2 > 0)
			{
				--count2;
				--m2[n];
			}
		}
		for (auto &[n, c] : m1)
		{
			if (count1 <= 0)
				break;
			if (m2[n] > 0)
			{
				--m1[n];
				--count1;
			}
		}
		for (auto &[n, c] : m2)
		{
			if (count2 <= 0)
				break;
			if (m2[n] > 0 && m1[n] > 0)
			{
				--m2[n];
				--count2;
			}
		}
		for (auto &[n, c] : m2)
			m1[n] += c;
		int res = 0;
		for (auto &[n, c] : m1)
		{
			if (c > 0)
				++res;
		}
		return res - count1 - count2;
	}
};