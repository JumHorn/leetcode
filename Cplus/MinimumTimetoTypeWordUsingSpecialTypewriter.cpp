#include <string>
using namespace std;

class Solution
{
public:
	int minTimeToType(string word)
	{
		int res = 0;
		char d = 'a';
		for (auto c : word)
		{
			res += min((d - c + 26) % 26, (c - d + 26) % 26);
			d = c;
		}
		return res + word.length();
	}
};