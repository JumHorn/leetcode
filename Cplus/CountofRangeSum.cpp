#include <vector>
using namespace std;

class Solution
{
public:
	int countRangeSum(vector<int> &nums, int lower, int upper)
	{
		int n = nums.size();
		low = lower;
		up = upper;
		vector<long> sums(n + 1);
		dup.resize(n + 1);
		for (int i = 0; i < n; ++i)
			sums[i + 1] = sums[i] + nums[i];
		return divide(sums, 0, n + 1);
	}

	int divide(vector<long> &sums, int start, int end)
	{
		int res = 0;
		if (end - start <= 1)
			return 0;
		int mid = start + (end - start) / 2;
		res = divide(sums, start, mid) + divide(sums, mid, end);
		for (int i = start, j = mid, k = mid; i < mid; ++i)
		{
			while (j < end && sums[j] - sums[i] < low)
				j++;
			while (k < end && sums[k] - sums[i] <= up)
				k++;
			res += k - j;
		}
		merge(sums, start, mid, end);
		return res;
	}

	void merge(vector<long> &sums, int start, int mid, int end)
	{
		int s = start, m = mid, d = 0, d1 = 0;
		while (s != mid && m != end)
			dup[d++] = (sums[s] > sums[m]) ? sums[m++] : sums[s++];
		while (s != mid)
			dup[d++] = sums[s++];
		while (m != end)
			dup[d++] = sums[m++];
		while (start != end)
			sums[start++] = dup[d1++];
	}

private:
	vector<int> dup;
	int low;
	int up;
};