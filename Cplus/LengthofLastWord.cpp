#include <string>
using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int i = s.length(), j = 0;
		for (--i; i >= 0 && s[i] == ' ';)
			--i;
		for (j = i; j >= 0 && s[j] != ' ';)
			--j;
		return i - j;
	}
};