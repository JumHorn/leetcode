#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minFlips(string target)
	{
		int flip = 0, res = 0;
		for (auto c : target)
		{
			if (c != flip % 2 + '0')
			{
				++flip;
				++res;
			}
		}
		return res;
	}
};