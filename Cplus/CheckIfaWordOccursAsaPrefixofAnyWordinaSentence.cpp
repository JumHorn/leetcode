#include <string>
using namespace std;

class Solution
{
public:
	int isPrefixOfWord(string sentence, string searchWord)
	{
		int size = sentence.length(), n = searchWord.length(), res = 1;
		for (int i = 0, j = 0; i < size;)
		{
			while (j < size && sentence[j] != ' ')
				++j;
			if (j - i >= n && sentence.substr(i, n) == searchWord)
				return res;
			i = ++j;
			++res;
		}
		return -1;
	}
};
