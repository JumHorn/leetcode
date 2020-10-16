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

	void divide(vector<pair<int, int>> &arr, vector<pair<int, int>> &dup, int start, int end, int &res)
	{
		if (end - start <= 1)
			return;
		int mid = start + (end - start) / 2;
		divide(arr, dup, start, mid, res);
		divide(arr, dup, mid, end, res);
		int index = 1e9; //min index
		for (int i = start, j = mid; j < end; ++j)
		{
			while (i < mid && arr[j].first >= arr[i].first)
			{
				index = min(index, arr[i].second);
				++i;
			}
			res = max(res, arr[j].second - index);
		}
		merge(arr, dup, start, mid, end);
	}

	void merge(vector<pair<int, int>> &arr, vector<pair<int, int>> &dup, int start, int mid, int end)
	{
		int s = start, m = mid, d = 0, d1 = 0;
		while (s != mid && m != end)
			dup[d++] = (arr[s] > arr[m]) ? arr[m++] : arr[s++];
		while (s != mid)
			dup[d++] = arr[s++];
		while (m != end)
			dup[d++] = arr[m++];
		while (start != end)
			arr[start++] = dup[d1++];
	}
};