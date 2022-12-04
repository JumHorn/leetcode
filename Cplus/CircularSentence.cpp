#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	bool isCircularSentence(string sentence)
	{
		if (sentence[0] != sentence.back())
			return false;
		stringstream ss(sentence);
		string word;
		ss >> word;
		char last = word.back();
		while (ss >> word)
		{
			if (last != word[0])
				return false;
			last = word.back();
		}
		return true;
	}
};