#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	char repeatedCharacter(string s)
	{
		vector<int> count(26);
		for (auto c : s)
		{
			if (++count[c - 'a'] == 2)
				return c;
		}
		return ' ';
	}
};