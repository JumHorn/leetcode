#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int numTriplets(vector<int> &nums1, vector<int> &nums2)
	{
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		return count(nums1, nums2) + count(nums2, nums1);
	}

	int count(vector<int> &nums1, vector<int> &nums2)
	{
		int res = 0;
		unordered_map<int, int> m; //{value,count}
		for (auto n1 : nums1)
		{
			m.clear();
			long n = (long)n1 * n1;
			for (auto n2 : nums2)
			{
				if (n % n2 == 0)
					res += m[n / n2];
				++m[n2];
			}
		}
		return res;
	}
};