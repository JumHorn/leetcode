#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
	{
		vector<int> A1, A2, B1, B2;
		split(nums1, A1, A2);
		split(nums2, B1, B2);
		long long sign = 0, negative = (long long)A1.size() * B2.size() + (long long)A2.size() * B1.size();
		if (k > negative)
		{
			k -= negative;
			sign = 1;
		}
		else
		{
			k = negative - k + 1;
			sign = -1;
			B1.swap(B2);
		}
		long long lo = 0, hi = 1e10;
		while (lo < hi)
		{
			long long mi = (hi - lo) / 2 + lo;
			if (count(A1, B1, mi) + count(A2, B2, mi) < k)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo * sign;
	}

	long long count(vector<int> &n1, vector<int> &n2, long long val)
	{
		long long res = 0, N1 = n1.size(), N2 = n2.size();
		for (int i = 0, j = N2 - 1; i < N1; ++i)
		{
			while (j >= 0 && (long long)n1[i] * n2[j] > val)
				--j;
			res += j + 1;
		}
		return res;
	}

	void split(vector<int> &nums, vector<int> &nums1, vector<int> &nums2)
	{
		for (auto n : nums)
		{
			if (n < 0)
				nums1.push_back(-n);
			else
				nums2.push_back(n);
		}
		reverse(nums1.begin(), nums1.end());
	}
};