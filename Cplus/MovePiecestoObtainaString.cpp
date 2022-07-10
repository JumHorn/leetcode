#include <string>
using namespace std;

class Solution
{
public:
	bool canChange(string start, string target)
	{
		int l = 0, r = 0;
		for (int i = 0; i < (int)start.length(); ++i)
		{
			if (start[i] != '_')
				start[i] == 'R' ? ++r : ++l;
			if ((r > 0 && l > 0) || (l < 0 && r > 0))
				return false;
			if (target[i] != '_')
				target[i] == 'R' ? --r : --l;
			if (l > 0 || r < 0 || (l < 0 && r > 0))
				return false;
		}
		return l == 0 && r == 0;
	}
};