#include <string>
using namespace std;

class Solution
{
public:
	int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
	{
		if (leaveAlice < arriveBob || arriveAlice > leaveBob)
			return 0;
		return dateDiff(max(arriveAlice, arriveBob), min(leaveAlice, leaveBob));
	}

	int dateDiff(const string &date1, const string &date2)
	{
		int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		int m1 = (date1[0] - '0') * 10 + date1[1] - '0', d1 = (date1[3] - '0') * 10 + date1[4] - '0';
		int m2 = (date2[0] - '0') * 10 + date2[1] - '0', d2 = (date2[3] - '0') * 10 + date2[4] - '0';
		if (m1 == m2)
			return d2 - d1 + 1;
		int res = d2 + mon[m1] - d1 + 1;
		for (int i = m1 + 1; i < m2; ++i)
			res += mon[i];
		return res;
	}
};