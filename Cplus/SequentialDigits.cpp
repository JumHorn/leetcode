#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sequentialDigits(int low, int high)
	{
		int sequence[] = {0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
		int increase[] = {0, 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111};
		int num = 0, tmp = low;
		while (tmp != 0)
		{
			num++;
			tmp /= 10;
		}
		vector<int> res;
		for (int i = num; i < 10 && sequence[i] <= high; ++i)
		{
			for (int j = 0; j < 10 - i; ++j)
			{
				tmp = sequence[i] + increase[i] * j;
				if (tmp > high)
					break;
				if (tmp >= low)
					res.push_back(tmp);
			}
		}
		return res;
	}
};
