#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> majorityElement(vector<int> &nums)
	{
		int count1 = 0, count2 = 0, value1, value2, N = nums.size();
		for (auto n : nums)
		{
			if (n == value1)
				++count1;
			else if (n == value2)
				++count2;
			else if (count1 == 0)
			{
				value1 = n;
				count1 = 1;
			}
			else if (count2 == 0)
			{
				value2 = n;
				count2 = 1;
			}
			else
			{
				--count1;
				--count2;
			}
		}

		count1 = count2 = 0;
		for (auto n : nums)
		{
			if (value1 == n)
				++count1;
			else if (value2 == n)
				++count2;
		}
		vector<int> res;
		if (count1 > N / 3)
			res.push_back(value1);
		if (count2 > N / 3)
			res.push_back(value2);
		return res;
	}
};