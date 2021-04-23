#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<double> getCollisionTimes(vector<vector<int>> &cars)
	{
		int N = cars.size();
		vector<double> res(N, -1.0);
		stack<int> s; //increasing speed cars
		s.push(N - 1);
		for (int i = N - 2; i >= 0; --i)
		{
			for (; !s.empty(); s.pop())
			{
				//top car fast than current car,may be we can catch up with next
				if (cars[s.top()][1] < cars[i][1])
				{
					//always exist so we can catch up finally
					if (res[s.top()] < 0)
						break;
					double distance = res[s.top()] * (cars[i][1] - cars[s.top()][1]);
					if (distance > cars[s.top()][0] - cars[i][0])
						break;
				}
			}
			if (!s.empty())
				res[i] = double(cars[s.top()][0] - cars[i][0]) / (cars[i][1] - cars[s.top()][1]);
			s.push(i);
		}
		return res;
	}
};