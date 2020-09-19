#include <vector>
using namespace std;

class Solution
{
public:
	int sumOddLengthSubarrays(vector<int> &arr)
	{
		int N = arr.size();
		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + arr[i];
		int res = 0;
		for (int n = 1; n <= N; n += 2)
		{
			for (int i = 0, j = n; j <= N; ++i, ++j)
				res += prefixsum[j] - prefixsum[i];
		}
		return res;
	}
};