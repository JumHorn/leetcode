#include <string>
using namespace std;

class Solution
{
public:
	bool sumGame(string num)
	{
		int num1 = 0, num2 = 0, mark1 = 0, mark2 = 0, N = num.size();
		for (int i = 0; i < N; ++i)
		{
			if (i < N / 2)
			{
				if (num[i] == '?')
					++mark1;
				else
					num1 += num[i] - '0';
			}
			else
			{
				if (num[i] == '?')
					++mark2;
				else
					num2 += num[i] - '0';
			}
		}
		if ((mark1 + mark2) % 2 == 1)
			return true;
		if (num1 > num2)
		{
			swap(num1, num2);
			swap(mark1, mark2);
		}
		int tmp = abs(mark1 - mark2);
		return num1 + tmp / 2 * 9 != num2;
	}
};