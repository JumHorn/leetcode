#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
	{
		multiset<int> s; //chargeTiems
		int i = 0, j = 0, N = chargeTimes.size();
		long long sum = 0;
		for (; i < N; ++i)
		{
			sum += runningCosts[i];
			long long cost = sum * (i + 1 - j);
			s.insert(chargeTimes[i]);
			int charge = *s.rbegin();
			if (budget < cost + charge)
			{
				sum -= runningCosts[j];
				s.erase(s.find(chargeTimes[j]));
				++j;
			}
		}
		return i - j;
	}
};