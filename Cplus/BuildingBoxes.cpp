
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
		for (; sum < n; sum += floor)
		{
			++addition;
			floor += addition;
		}
		if (sum == n)
			return floor;
		sum -= floor;
		floor -= addition;
		addition = 0;
		for (; sum < n; sum += addition)
			++addition;
		return floor + addition;
	}
};