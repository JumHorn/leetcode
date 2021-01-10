#include <vector>
using namespace std;

/*
merge sort
*/

class Solution
{
public:
	int maxWidthRamp(vector<int> &A)
	{
		int res = 0, N = A.size();
		vector<pair<int, int>> arr, dup(N); //{val,index}
		for (int i = 0; i < N; ++i)
			arr.push_back({A[i], i});
		divide(arr, dup, 0, N, res);
		return res;
	}

	void divide(vector<pair<int, int>> &arr, vector<pair<int, int>> &dup, int first, int last, int &res)
	{
		if (last - first <= 1)
			return;
		int mid = first + (last - first) / 2;
		divide(arr, dup, first, mid, res);
		divide(arr, dup, mid, last, res);
		int index = 1e9; //min index
		for (int i = first, j = mid; j < last; ++j)
		{
			for (; i < mid && arr[j].first >= arr[i].first; ++i)
				index = min(index, arr[i].second);
			res = max(res, arr[j].second - index);
		}
		merge(arr, dup, first, mid, last);
	}

	void merge(vector<pair<int, int>> &arr, vector<pair<int, int>> &dup, int first, int mid, int last)
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
};