#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string firstPalindrome(vector<string> &words)
	{
		for (auto &w : words)
		{
			if (isPalindrome(w))
				return w;
		}
		return "";
	}

	bool isPalindrome(string &word)
	{
		for (int i = 0, j = (int)word.length() - 1; i < j; ++i, --j)
		{
			if (word[i] != word[j])
				return false;
		}
		return true;
	}
};