#include <vector>
using namespace std;

class Solution
{
public:
	int findDuplicate(vector<int> &nums)
	{
		int tortoise = 0, hare = nums[0];
		while (tortoise != hare)
		{
			tortoise = nums[tortoise];
			hare = nums[nums[hare]];
		}
		tortoise = 0;
		hare = nums[hare];
		while (tortoise != hare)
		{
			tortoise = nums[tortoise];
			hare = nums[hare];
		}
		return tortoise;
	}
};