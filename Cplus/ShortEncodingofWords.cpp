#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumLengthEncoding(vector<string> &words)
	{
		unordered_set<string> s(words.begin(), words.end());
		for (auto &word : s)
		{
			for (int i = 1; i < (int)word.length(); ++i)
				s.erase(word.substr(i));
		}
		int res = 0;
		for (auto &word : s)
			res += word.length() + 1;
		return res;
	}
};