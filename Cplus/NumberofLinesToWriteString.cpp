#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numberOfLines(vector<int> &widths, string S)
	{
		int line = 1, len = 0;
		for (auto c : S)
		{
			len += widths[c - 'a'];
			if (len == 100)
			{
				len = 0;
				++line;
			}
			else if (len > 100)
			{
				len = widths[c - 'a'];
				++line;
			}
		}
		return {line, len};
	}
};