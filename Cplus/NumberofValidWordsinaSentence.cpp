#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	int countValidWords(string sentence)
	{
		stringstream ss(sentence);
		string word;
		int res = 0;
		while (ss >> word)
		{
			if (word == "!" || word == "." || word == ",")
			{
				++res;
				continue;
			}
			if (word.back() == ',' || word.back() == '.' || word.back() == '!')
				word.pop_back();
			if (!word.empty() && valid(word))
				++res;
		}
		return res;
	}

	bool valid(string &word)
	{
		int N = word.length(), count = 0; // - count
		for (int i = 0; i < N; ++i)
		{
			if (word[i] == '-')
				++count;
			else if (!isalpha(word[i]))
				return false;
		}
		return count <= 1 && word.front() != '-' && word.back() != '-';
	}
};