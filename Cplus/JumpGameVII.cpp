#include <set>
#include <string>
using namespace std;

class Solution
{
public:
	bool canReach(string s, int minJump, int maxJump)
	{
		int N = s.length();
		if (s.back() == '1')
			return false;
		set<int> pos;
		pos.insert(0);
		for (int i = 1; i < N; ++i)
		{
			if (s[i] == '0')
			{
				if (i - maxJump <= 0 && i >= minJump)
					pos.insert(i);
				else
				{
					auto iter = pos.upper_bound(i - minJump);
					if (iter != pos.begin())
					{
						--iter;
						if (i - *iter <= maxJump)
							pos.insert(i);
					}
				}
			}
		}
		return pos.find(N - 1) != pos.end();
	}
};