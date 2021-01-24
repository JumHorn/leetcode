
/*
1 3 6 10 15 floor
1 4 10 20 35 max placed
*/

class Solution
{
public:
	int minimumBoxes(int n)
	{
		int sum = 0, floor = 0, addition = 0;
		while (sum < n)
		{
			++addition;
			floor += addition;
			sum += floor;
		}
		if (sum == n)
			return floor;
		sum -= floor;
		floor -= addition;
		addition = 0;
		while (sum < n)
		{
			++addition;
			sum += addition;
		}
		return floor + addition;
	}
};