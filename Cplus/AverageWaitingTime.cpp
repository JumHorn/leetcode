#include <vector>
using namespace std;

class Solution
{
public:
	double averageWaitingTime(vector<vector<int>> &customers)
	{
		long sum = 0, N = customers.size(), time = 0;
		for (auto &v : customers)
		{
			time = max(time, (long)v[0]);
			time += v[1];
			sum += time - v[0];
		}
		return sum * 1.0 / N;
	}
};