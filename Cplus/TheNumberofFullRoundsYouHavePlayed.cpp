#include <string>
using namespace std;

class Solution
{
public:
	int numberOfRounds(string startTime, string finishTime)
	{
		int res = 0, sh, sm, fh, fm; //start hour,start minute,finish hour,finish minute
		sh = stoi(startTime.substr(0, 2));
		sm = stoi(startTime.substr(3, 2));
		fh = stoi(finishTime.substr(0, 2));
		fm = stoi(finishTime.substr(3, 2));
		if (startTime > finishTime)
			fh += 24;
		fm = fm / 15 * 15;
		sm = (sm / 15 + (sm % 15 == 0 ? 0 : 1)) * 15;
		if (sm >= 60)
		{
			sm -= 60;
			++sh;
		}
		while (sh < fh || (sh == fh && sm < fm))
		{
			++res;
			sm += 15;
			if (sm >= 60)
			{
				sm -= 60;
				++sh;
			}
		}
		return res;
	}
};