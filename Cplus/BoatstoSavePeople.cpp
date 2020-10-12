#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int numRescueBoats(vector<int> &people, int limit)
	{
		sort(people.begin(), people.end());
		int i = 0, j = (int)people.size() - 1, res = 0;
		while (i <= j)
		{
			if (people[i] + people[j] <= limit)
				++i;
			--j;
			++res;
		}
		return res;
	}
};