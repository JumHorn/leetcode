#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfSpecialChars(string word)
	{
		vector<int> lower(26), upper(26);
		for (auto c : word)
		{
			if (islower(c))
				lower[c - 'a'] = 1;
			else
				upper[c - 'A'] = 1;
		}
		int res = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (lower[i] == 1 && upper[i] == 1)
				++res;
		}
		return res;
	}
};