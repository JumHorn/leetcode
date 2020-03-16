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
			if (c == 'z')
			{
				char move = (j - y >= 0 ? 'L' : 'R');
				if (abs(j - y) > 0)
					res += string(abs(j - y), move);
				move = (i - x >= 0 ? 'U' : 'D');
				if (abs(i - x) > 0)
					res += string(abs(i - x), move);
			}
			else
			{
				char move = (i - x >= 0 ? 'U' : 'D');
				if (abs(i - x) > 0)
					res += string(abs(i - x), move);
				move = (j - y >= 0 ? 'L' : 'R');
				if (abs(j - y) > 0)
					res += string(abs(j - y), move);
			}
			res += '!';
			i = x;
			j = y;
		}
		return res;
	}
};
