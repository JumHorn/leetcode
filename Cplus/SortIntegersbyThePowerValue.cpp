#include <queue>
using namespace std;

class Solution
{
public:
	int getKth(int lo, int hi, int k)
	{
		priority_queue<pair<int, int>> q;
		for (int i = lo; i <= hi; i++)
			q.push({-power(i), -i});
		while (--k > 0)
		{
			q.pop();
		}
		return -q.top().second;
	}

	int power(int x)
	{
		int res = 1;
		while (x != 1)
		{
			if (x % 2 == 0)
				x /= 2;
			else
				x = 3 * x + 1;
			res++;
		}
		return res;
	}
};
