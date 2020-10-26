#include <string>
using namespace std;

/*
If there is such pattern, the original string could be represented as following:
origin_str = pattern + pattern + ... + pattern =  m * pattern;
With doubling:
origin_str + origin_str = 2 * m * pattern;
After removing head and rear:
new_str = pattern_wo_head + (2m-2) * pattern + pattern_wo_rear
So, origin_str(m * pattern) could be found in new_str if m >= 2.
*/

class Solution
{
public:
	bool repeatedSubstringPattern(string s)
	{
		return (s + s).find(s, 1) < s.length();
	}
};