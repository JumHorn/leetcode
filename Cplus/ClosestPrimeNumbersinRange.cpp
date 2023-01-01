#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> closestPrimes(int left, int right)
	{
		const int MAX = 1e6 + 1;
		vector<int> p(MAX);
		for (int i = 2; i < MAX; ++i)
		{
			if (p[i] == 0)
			{
				for (int j = i + i; j < MAX; j += i)
					p[j] = 1;
			}
		}

		vector<int> num;
		for (int i = 2; i < MAX; ++i)
		{
			if (p[i] == 0)
			{
				if (i >= left && i <= right)
					num.push_back(i);
			}
		}
		if (num.size() < 2)
			return {-1, -1};
		vector<int> res = {num[0], num[1]};
		for (int i = 1; i < (int)num.size(); ++i)
		{
			if (res[1] - res[0] > num[i] - num[i - 1])
				res = {num[i - 1], num[i]};
		}
		return res;
	}
};