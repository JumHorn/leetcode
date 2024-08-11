#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int finalPositionOfSnake(int n, vector<string> &commands)
	{
		int res = 0;
		for (auto &str : commands)
		{
			if (str[0] == 'U')
				res -= n;
			else if (str[0] == 'D')
				res += n;
			else if (str[0] == 'R')
				res += 1;
			else
				res -= 1;
		}
		return res;
	}
};