#include <string>
using namespace std;

class Solution
{
public:
	int addMinimum(string word)
	{
		int N = word.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (i + 2 < N && word[i] < word[i + 1] && word[i + 1] < word[i + 2]) // abc
				i += 2;
			else if (i + 1 < N && word[i] < word[i + 1]) // ab,ac,bc
			{
				++res;
				++i;
			}
			else
				res += 2;
		}
		return res;
	}
};