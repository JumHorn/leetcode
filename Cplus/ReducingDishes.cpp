#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSatisfaction(vector<int> &satisfaction)
	{
		sort(satisfaction.begin(), satisfaction.end());
		int index = binarySearch(satisfaction), n = satisfaction.size();
		int sum = 0, res = 0;
		for (int i = index; i < n; i++)
		{
			res += satisfaction[i] * (i - index + 1);
			sum += satisfaction[i];
		}
		if (satisfaction.front() >= 0)
			return res;
		if (satisfaction.back() <= 0)
			return 0;
		int negsum = 0, minus = 0;
		while (--index >= 0 && -(negsum + satisfaction[index]) < sum)
		{
			minus += satisfaction[index] + negsum;
			negsum += satisfaction[index];
			res += sum;
		}
		return res + minus;
	}

	int binarySearch(vector<int> &satisfaction)
	{
		int lo = 0, hi = satisfaction.size() - 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (satisfaction[mi] >= 0)
				hi = mi;
			else
				lo = mi + 1;
		}
		return lo;
	}
};