#include <string>
using namespace std;

class Solution
{
public:
	bool judgeCircle(string moves)
	{
		int h = 0, v = 0; //horizantal and vertical
		for (auto c : moves)
		{
			if (c == 'R')
				++h;
			else if (c == 'L')
				--h;
			else if (c == 'U')
				++v;
			else
				--v;
		}
		return h == 0 && v == 0;
	}
};