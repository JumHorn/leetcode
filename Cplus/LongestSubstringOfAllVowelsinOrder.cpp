#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int longestBeautifulSubstring(string word)
	{
		int res = 0, N = word.length();
		unordered_set<char> s;
		s.insert(word[0]);
		for (int i = 1, j = 0; i <= N; ++i)
		{
			if (i == N || word[i] < word[i - 1])
			{
				if (s.size() == 5)
					res = max(res, i - j);
				j = i;
				s.clear();
			}
			s.insert(word[i]);
		}
		return res;
	}
};