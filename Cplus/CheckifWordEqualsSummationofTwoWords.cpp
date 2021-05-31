#include <string>
using namespace std;

class Solution
{
public:
	bool isSumEqual(string firstWord, string secondWord, string targetWord)
	{
		int a = getValue(firstWord), b = getValue(secondWord), c = getValue(targetWord);
		return a + b == c;
	}

	int getValue(string word)
	{
		int res = 0;
		for (auto c : word)
			res = res * 10 + c - 'a';
		return res;
	}
};