#include <string>
using namespace std;

class Solution
{
public:
	int secondsToRemoveOccurrences(string s)
	{
		int res = -1, N = s.size();
		bool flag = true;
		while (flag)
		{
			flag = false;
			++res;
			for (int i = 0; i < N; ++i)
			{
				if (s[i] == '0' && s[i + 1] == '1')
				{
					swap(s[i], s[i + 1]);
					++i;
					flag = true;
				}
			}
		}
		return res;
	}
};