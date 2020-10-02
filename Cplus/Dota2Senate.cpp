#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
	string predictPartyVictory(string senate)
	{
		queue<char> q;
		for (auto c : senate)
			q.push(c);
		int right = 0;
		while (!q.empty())
		{
			int size = q.size(), r = 0, d = 0;
			while (--size >= 0)
			{
				char senator = q.front();
				q.pop();
				if (senator == 'R')
				{
					if (--right < 0)
					{
						++r;
						q.push(senator);
					}
				}
				else
				{
					if (++right > 0)
					{
						++d;
						q.push(senator);
					}
				}
			}
			if (r == 0)
				return "Dire";
			if (d == 0)
				return "Radiant";
		}
		return "";
	}
};