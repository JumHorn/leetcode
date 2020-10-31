#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> distributeCandies(int candies, int num_people)
	{
		vector<int> res(num_people);
		for (int i = 0, j = 1; candies > 0; i = (i + 1) % num_people)
		{
			res[i] += min(j, candies);
			candies -= j++;
		}
		return res;
	}
};