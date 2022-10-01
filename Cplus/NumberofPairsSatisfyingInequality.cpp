#include <vector>
using namespace std;

class Solution
{
public:
	long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
	{
		long long res = 0;
		int N = nums1.size();
		vector<long long> d(N), dup(N);
		for (int i = 0; i < N; ++i)
			d[i] = nums1[i] - nums2[i];
		return divide(d, dup, 0, N, diff);
	}

	//divide and conquer
	long long divide(vector<long long> &arr, vector<long long> &dup, int first, int last, int diff)
	{
		if (last - first <= 1)
			return 0;
		long long mid = first + (last - first) / 2, res = 0;
		res += divide(arr, dup, first, mid, diff);
		res += divide(arr, dup, mid, last, diff);
		for (int i = first, j = mid; i < mid; ++i)
		{
			while (j != last && arr[i] - arr[j] > diff)
				++j;
			res += last - j;
		}
		merge(arr, dup, first, mid, last);
		return res;
	}

	void merge(vector<long long> &arr, vector<long long> &dup, int first, int mid, int last)
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