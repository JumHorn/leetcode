#include <vector>
using namespace std;

class Solution
{
public:
	bool lemonadeChange(vector<int> &bills)
	{
		int five = 0, ten = 0, N = bills.size();
		for (int i = 0; i < N && five >= 0; ++i)
		{
			if (bills[i] == 5)
				++five;
			else if (bills[i] == 10)
			{
				--five;
				++ten;
			}
			else //bills[i]==20
			{
				if (ten > 0)
				{
					--ten;
					--five;
				}
				else
					five -= 3;
			}
		}
		return five >= 0;
	}
};