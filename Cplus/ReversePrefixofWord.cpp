#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string reversePrefix(string word, char ch)
	{
		int N = word.length(), i = 0;
		for (; i < N; ++i)
		{
			if (ch == word[i])
				break;
		}
		if (i == N)
			return word;
		reverse(word.begin(), word.begin() + i + 1);
		return word;
	}
};