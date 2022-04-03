#include <string>
using namespace std;

class Solution
{
public:
	int convertTime(string current, string correct)
	{
		int cur = (current[0] * 10 + current[1]) * 60 + current[3] * 10 + current[4];
		int cor = (correct[0] * 10 + correct[1]) * 60 + correct[3] * 10 + correct[4];
		int res = 0, diff = cor - cur;
		int op[] = {60, 15, 5, 1};
		for (int i = 0; i < 4; ++i)
		{
			res += diff / op[i];
			diff %= op[i];
		}
		return res;
	}
};