#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
	bool detectCapitalUse(string word)
	{
		return all_of(word.begin(), word.end(), ::isupper) ||
			   all_of(word.begin(), word.end(), ::islower) ||
			   (isupper(word.front()) && all_of(word.begin() + 1, word.end(), ::islower));
	}
};