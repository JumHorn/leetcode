#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int candy(vector<int> &ratings)
	{
		if (ratings.empty())
			return 0;
		int N = ratings.size();
		vector<int> res(N, 1);
		for (int i = 1; i < N; ++i)
		{
			if (ratings[i - 1] < ratings[i])
				res[i] = res[i - 1] + 1;
		}
		for (int i = N - 2; i >= 0; --i)
		{
			if (ratings[i] > ratings[i + 1])
				res[i] = max(res[i], res[i + 1] + 1);
		}
		return accumulate(res.begin(), res.end(), 0);
	}
};