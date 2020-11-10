#include <vector>
using namespace std;

class Solution
{
public:
	int countRangeSum(vector<int> &nums, int lower, int upper)
	{
		int N = nums.size();
		vector<long> prefixsum(N + 1), dup(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + nums[i];
		return divide(prefixsum, dup, 0, N + 1, lower, upper);
	}

	//divide and conquer
	int divide(vector<long> &arr, vector<long> &dup, int first, int last, int lower, int upper)
	{
		if (last - first <= 1)
			return 0;
		int mid = first + (last - first) / 2, res = 0;
		res += divide(arr, dup, first, mid, lower, upper);
		res += divide(arr, dup, mid, last, lower, upper);
		for (int i = first, j = mid, k = mid; i < mid; ++i)
		{
			while (j < last && arr[j] - arr[i] < lower)
				++j;
			while (k < last && arr[k] - arr[i] <= upper)
				++k;
			res += k - j;
		}
		merge(arr, dup, first, mid, last);
		return res;
	}

	void merge(vector<long> &arr, vector<long> &dup, int first, int mid, int last)
	{
		for (int i = first, j = mid, d = 0; i < mid || j < last;)
		{
			if (i == mid)
				dup[d++] = arr[j++];
			else if (j == last)
				dup[d++] = arr[i++];
			else
				dup[d++] = (arr[i] > arr[j]) ? arr[j++] : arr[i++];
		}
		for (int i = first, j = 0; i < last; ++i, ++j)
			arr[i] = dup[j];
	}
	/********end of divide and conquer********/
};