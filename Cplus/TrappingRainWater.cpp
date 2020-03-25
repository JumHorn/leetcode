#include <vector>
using namespace std;

/*
1. find all the maximum and minimum value of the height and store them in peek
2. fill water in V like pattern (up low up)
*/

class Solution
{
public:
	int trap(vector<int> &height)
	{
		if (height.empty())
			return 0;
		//find all the maximum and minimum value of the height
		vector<int> peek;
		int n = height.size();
		peek.push_back(0);
		for (int i = 1; i < n - 1;)
		{
			int j = i + 1;
			while (j + 1 < n && height[j] == height[i])
				j++;
			if ((height[i - 1] - height[i]) * (height[i] - height[j]) < 0)
				peek.push_back(i);
			i = j;
		}
		peek.push_back(n - 1);

		//find the first low point as index
		if (peek.size() <= 2u)
			return 0;
		int index = 1;
		if (height[peek[1]] > height[0])
		{
			if (peek.size() == 3u)
				return 0;
			index = 2;
		}
		//add the water to res and fill the hole
		int res = 0;
		for (; index < (int)peek.size() - 1; index += 2)
		{
			int low = min(height[peek[index - 1]], height[peek[index + 1]]);
			res += low * (peek[index + 1] - peek[index - 1] - 1) - sum(height, peek[index - 1] + 1, peek[index + 1], low);
		}
		res += trap(height); //once again until no low point in height array
		return res;
	}

	int sum(vector<int> &height, int i, int j, int low)
	{
		int res = 0;
		for (int k = i; k < j; k++)
		{
			res += min(height[k], low);
			if (height[k] < low)
				height[k] = low;
		}
		return res;
	}
};