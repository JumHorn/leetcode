#include <string>
using namespace std;

class Solution
{
public:
	bool doesAliceWin(string s)
	{
		int count = 0;
		for (auto c : s)
		{
			if (isvowel(c))
				++count;
		}
		return count != 0;
	}

	bool isvowel(char ch)
	{
		string vowels = "aeiou";
		for (auto c : vowels)
		{
			if (c == ch)
				return true;
		}
		return false;
	}
};