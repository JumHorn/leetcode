#include <string>
using namespace std;

class Solution
{
public:
	int countBinarySubstrings(string s)
	{
		int curContiguousCount = 0, preContiguousCount = 0, res = 0;
		char bin = '\0';
		for (auto c : s)
		{
			if (bin != c)
			{
				bin = c;
				preContiguousCount = curContiguousCount;
				curContiguousCount = 0;
			}
			if (++curContiguousCount <= preContiguousCount)
				++res;
		}
		return res;
	}
};