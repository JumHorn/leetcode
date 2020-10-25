#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int findBestValue(vector<int> &arr, int target)
	{
		int N = arr.size();
		sort(arr.begin(), arr.end());
		vector<int> sum(N + 1); //if current value choosed as best ,then calculate sum
		for (int i = 0; i < N; ++i)
			sum[i + 1] = sum[i] + arr[i];
		for (int i = N - 1; i >= 0; --i)
			sum[i + 1] = arr[i] * (N - i) + sum[i];
		if (sum.back() <= target)
			return arr.back();
		int lo = 0, hi = N + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (sum[mi] < target)
				lo = mi + 1;
			else
				hi = mi;
		}
		target -= sum[--lo];
		//slightly increase the last value with int(target * 1.0 / (N - lo) + 0.4)
		return int(target * 1.0 / (N - lo) + 0.4) + (lo >= 1 ? arr[lo - 1] : 0);
	}
};