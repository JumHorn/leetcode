#include <unordered_map>
using namespace std;

class Solution
{
public:
	int memdp(int n, unordered_map<int, int>& cache)
	{
		if (n == 0)
			return 0;
		if (cache.find(n) != cache.end())
			return cache[n];
		int res = 1 + n % 2 + memdp(n / 2, cache);
		res = min(res, 1 + n % 3 + memdp(n / 3, cache));
		return cache[n] = res;
	}

	int minDays(int n)
	{
		unordered_map<int, int> cache;
		return memdp(n, cache) - 1;
	}
};
