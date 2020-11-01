#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	int isPrefixOfWord(string sentence, string searchWord)
	{
		stringstream ss(sentence);
		string word;
		int N = searchWord.size();
		for (int i = 1; ss >> word; ++i)
		{
			if (word.compare(0, N, searchWord) == 0)
				return i;
		}
		return -1;
	}
};