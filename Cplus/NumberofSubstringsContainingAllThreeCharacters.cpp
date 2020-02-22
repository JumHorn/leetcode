#include <string>
using namespace std;

class Solution
{
public:
	int numberOfSubstrings(string s)
	{
		int count[3] = {0}, res = 0;
		count[s[0] - 'a']++;
		count[s[1] - 'a']++;
		count[s[2] - 'a']++;
		if (count[0] != 0 && count[1] != 0 && count[2] != 0)
			res = 1;
		for (int i = 3, j = 0; i < (int)s.length(); i++)
		{
			count[s[i] - 'a']++;
			while (count[s[j] - 'a'] > 1)
			{
				count[s[j] - 'a']--;
				j++;
			}
			if (count[0] != 0 && count[1] != 0 && count[2] != 0)
				res += j + 1;
		}
		return res;
	}
};
