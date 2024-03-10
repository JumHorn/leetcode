#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumHappinessSum(vector<int> &happiness, int k)
	{
		sort(happiness.begin(), happiness.end(), greater<int>());
		long long res = 0, d = 0;
		for (int i = 0; i < k; ++i)
		{
			happiness[i] -= d;
			d++;
			if (happiness[i] <= 0)
				break;
			res += happiness[i];
		}
		return res;
	}
};