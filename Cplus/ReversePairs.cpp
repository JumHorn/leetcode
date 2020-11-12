#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int reversePairs(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> dup(N);
		return divide(nums, dup, 0, N);
	}

	//divide and conquer
	void merge(vector<int> &arr, vector<int> &dup, int first, int mid, int last)
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

	int divide(vector<int> &arr, vector<int> &dup, int first, int last)
	{
		if (last - first <= 1)
			return 0;
		int mid = first + (last - first) / 2, res = 0;
		res += divide(arr, dup, first, mid);
		res += divide(arr, dup, mid, last);
		for (int i = first, j = mid; i < mid; ++i)
		{
			while (j < last && (long)arr[i] > 2L * arr[j])
				++j;
			res += j - mid;
		}
		merge(arr, dup, first, mid, last);
		return res;
	}
	/********end of divide and conquer********/
};