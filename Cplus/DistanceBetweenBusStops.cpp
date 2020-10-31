#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
	{
		int clock = 0, counter_clock = 0, N = distance.size();
		for (int i = start; i != destination; i = (i + 1) % N)
			clock += distance[i];
		for (int i = start; i != destination;)
		{
			i = ((i - 1) + N) % N;
			counter_clock += distance[i];
		}
		return min(clock, counter_clock);
	}
};