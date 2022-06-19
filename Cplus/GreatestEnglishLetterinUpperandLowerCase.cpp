#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string greatestLetter(string s)
	{
		vector<int> lower(26), upper(26);
		for (auto c : s)
		{
			if (islower(c))
				lower[c - 'a'] = 1;
			else
				upper[c - 'A'] = 1;
		}
		for (int i = 25; i >= 0; --i)
		{
			if (lower[i] == 1 && upper[i] == 1)
				return string(1, char(i + 'A'));
		}
		return "";
	}
};