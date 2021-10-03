#include <string>
using namespace std;

class Solution
{
public:
	int maxConsecutiveAnswers(string answerKey, int k)
	{
		int t = slidewindow(answerKey, k, 'T');
		int f = slidewindow(answerKey, k, 'F');
		return max(t, f);
	}

	int slidewindow(string &key, int k, char c)
	{
		int i = 0, j = 0, N = key.length();
		for (; j < N; ++j)
		{
			if (key[j] != c)
				--k;
			if (k < 0)
			{
				if (key[i] != c)
					++k;
				++i;
			}
		}
		return j - i;
	}
};