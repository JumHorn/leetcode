#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes)
	{
		long long res = -1, N = packages.size();
		sort(packages.begin(), packages.end());
		vector<long> prefix(N + 1);
		for (int i = 0; i < N; ++i)
			prefix[i + 1] = prefix[i] + packages[i];
		for (auto box : boxes)
		{
			sort(box.begin(), box.end());
			if (packages.back() > box.back())
				continue;
			int lo = 0;
			long long waste = 0;
			for (int i = 0; lo < N; ++i)
			{
				int tmp = binarySearch(packages, lo, N, box[i]);
				waste += (long)box[i] * (tmp - lo) - (prefix[tmp] - prefix[lo]);
				lo = tmp;
			}

			if (res == -1)
				res = waste;
			res = min(res, waste);
		}
		if (res == -1)
			return res;
		return res % MOD;
	}

	int binarySearch(vector<int> &arr, int lo, int hi, int val)
	{
		if (arr.back() <= val)
			return hi;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (arr[mi] <= val)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

private:
	static const int MOD = 1e9 + 7;
};