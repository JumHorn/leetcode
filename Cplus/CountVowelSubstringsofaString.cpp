#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int countVowelSubstrings(string word)
	{
		int N = word.length(), res = 0;
		vector<int> vowel(128);
		vowel['a'] = 1;
		vowel['e'] = 1;
		vowel['i'] = 1;
		vowel['o'] = 1;
		vowel['u'] = 1;
		for (int i = 0; i < N; ++i)
		{
			unordered_set<int> count;
			for (int j = i; j < N; ++j)
			{
				if (vowel[word[j]] == 0)
					break;
				count.insert(word[j]);
				if (count.size() >= 5)
					++res;
			}
		}
		return res;
	}
};