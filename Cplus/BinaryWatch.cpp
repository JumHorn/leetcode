#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> readBinaryWatch(int num)
	{
		vector<string> res;
		for (int hour = 0; hour < 12; ++hour)
		{
			for (int minute = 0; minute < 60; ++minute)
			{
				if (bitCount(hour) + bitCount(minute) == num)
					res.push_back(to_string(hour) + ":" + (minute < 10 ? "0" : "") + to_string(minute));
			}
		}
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		while (n != 0)
		{
			++res;
			n &= n - 1;
		}
		return res;
	}
};