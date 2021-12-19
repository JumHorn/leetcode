#include <vector>
using namespace std;

class Solution
{
public:
	int kIncreasing(vector<int> &arr, int k)
	{
		int N = arr.size(), res = 0;
		for (int i = 0; i < k; ++i)
		{
			vector<int> v;
			for (int j = i; j < N; j += k)
				v.push_back(arr[j]);
			res += v.size() - lengthOfLIS(v);
		}
		return res;
	}

	int lengthOfLIS(vector<int> &arr)
	{
		int size = 0, N = arr.size();
		for (int i = 0; i < N; ++i)
		{
			int lo = 0, hi = size;
			while (lo < hi)
			{
				int mi = (hi - lo) / 2 + lo;
				if (arr[mi] <= arr[i])
					lo = mi + 1;
				else
					hi = mi;
			}
			arr[lo] = arr[i];
			if (lo == size)
				++size;
		}
		return size;
	}
};