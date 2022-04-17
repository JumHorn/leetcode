#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumRounds(vector<int> &tasks)
	{
		sort(tasks.begin(), tasks.end());
		int N = tasks.size(), res = 0;
		for (int i = 0, j = 0; i <= N; ++i)
		{
			if (i == N || tasks[i] != tasks[j])
			{
				int count = i - j;
				j = i;
				if (count == 1)
					return -1;
				res += count / 3;
				if (count % 3 != 0)
					++res;
			}
		}
		return res;
	}
};