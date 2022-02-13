#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumRemoval(vector<int> &beans)
	{
		sort(beans.begin(), beans.end());
		long long res = accumulate(beans.begin(), beans.end(), 0LL), sum = res;
		int N = beans.size();
		for (int i = 0; i < N; ++i)
			res = min(res, sum - (long long)beans[i] * (N - i));
		return res;
	}
};