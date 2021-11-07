#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	long long countVowels(string word)
	{
		vector<int> vowel(128);
		vowel['a'] = 1;
		vowel['e'] = 1;
		vowel['i'] = 1;
		vowel['o'] = 1;
		vowel['u'] = 1;
		int N = word.length();
		long long res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (vowel[word[i]] == 1)
			{
				res += (long long)(i + 1) * (N - i);
			}
		}
		return res;
	}
};