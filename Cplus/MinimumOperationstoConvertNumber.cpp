#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumOperations(vector<int> &nums, int start, int goal)
	{
		queue<int> q;
		vector<int> seen(1001);
		int res = 0;
		q.push(start);
		seen[start] = 1;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				int x = q.front();
				q.pop();
				for (auto n : nums)
				{
					if (x + n == goal)
						return res;
					if (x + n <= 1000 && x + n >= 0 && seen[x + n] == 0)
					{
						q.push(x + n);
						seen[x + n] = 1;
					}

					if (x - n == goal)
						return res;
					if (x - n <= 1000 && x - n >= 0 && seen[x - n] == 0)
					{
						q.push(x - n);
						seen[x - n] = 1;
					}
					if ((x ^ n) == goal)
						return res;
					if ((x ^ n) <= 1000 && (x ^ n) >= 0 && seen[x ^ n] == 0)
					{
						q.push(x ^ n);
						seen[x ^ n] = 1;
					}
				}
			}
		}
		return -1;
	}
};