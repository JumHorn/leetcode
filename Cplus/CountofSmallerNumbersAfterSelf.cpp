#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countSmaller(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> res(N);
		vector<pair<int, int>> pairs(N), dup(N); //{value,index}
		for (int i = 0; i < N; ++i)
		{
			pairs[i].first = nums[i];
			pairs[i].second = i;
		}
		divide(pairs, dup, 0, N, res);
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

	void divide(vector<pair<int, int>> &pairs, vector<pair<int, int>> &dup, int first, int last, vector<int> &res)
	{
		if (last - first <= 1)
			return;
		int mid = first + (last - first) / 2;
		divide(pairs, dup, first, mid, res);
		divide(pairs, dup, mid, last, res);
		for (int i = first, j = mid; i < mid; ++i)
		{
			while (j != last && pairs[i].first > pairs[j].first)
				++j;
			res[pairs[i].second] += j - mid;
		}
		merge(pairs, dup, first, mid, last);
	}
	/********end of divide and conquer********/
};