#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int heightChecker(vector<int> &heights)
	{
		vector<int> people = heights;
		sort(people.begin(), people.end());
		int res = 0;
		for (int i = 0; i < (int)heights.size(); ++i)
		{
			if (people[i] != heights[i])
				++res;
		}
		return res;
	}
};