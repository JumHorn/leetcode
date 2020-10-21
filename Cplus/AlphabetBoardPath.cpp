#include <string>
using namespace std;

class Solution
{
public:
	string alphabetBoardPath(string target)
	{
		int i = 0, j = 0, n = 5;
		string res;
		for (auto c : target)
		{
			int x = (c - 'a') / n, y = (c - 'a') % n;
			res += string(max(0, i - x), 'U') + string(max(0, y - j), 'R') +
				   string(max(0, j - y), 'L') + string(max(0, x - i), 'D') + "!";
			i = x;
			j = y;
		}
		return res;
	}
};