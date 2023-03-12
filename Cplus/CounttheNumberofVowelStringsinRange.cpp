#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int vowelStrings(vector<string> &words, int left, int right)
	{
		int res = 0;
		for (int i = left; i <= right; ++i)
		{
			if (isvowel(words[i][0]) && isvowel(words[i].back()))
				++res;
		}
		return res;
	}

	bool isvowel(char c)
	{
		string vowel = "aeiou";
		for (auto v : vowel)
		{
			if (v == c)
				return true;
		}
		return false;
	}
};