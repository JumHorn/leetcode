#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
	{
		int N = index.size();
		// this O(n^2) part can be optimized using BIT to O(nlogn)
		// for (int i = 0; i < indexSize; ++i)
		// {
		// 	for (int j = i + 1; j < indexSize; ++j)
		// 	{
		// 		if (index[i] >= index[j])
		// 			++index[i];
		// 	}
		// }
		vector<pair<int, int>> v, dup(N); //{new val,origin index}
		for (int i = 0; i < N; ++i)
			v.push_back({index[i], i});
		divide(v, dup, 0, N);
		vector<int> res(N);
		for (int i = 0; i < N; ++i)
			res[v[i].first] = nums[v[i].second];
		return res;
	}

	//divide and conquer
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

	void divide(vector<pair<int, int>> &arr, vector<pair<int, int>> &dup, int first, int last)
	{
		if (last - first <= 1)
			return;
		int mid = first + (last - first) / 2;
		divide(arr, dup, first, mid);
		divide(arr, dup, mid, last);
		for (int i = first, j = mid, count = 0; i < mid; ++i)
		{
			for (; j < last && arr[i].first + count >= arr[j].first; ++j)
				++count;
			arr[i].first += count;
		}
		merge(arr, dup, first, mid, last);
	}
	/********end of divide and conquer********/
};