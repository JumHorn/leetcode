#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string oddString(vector<string> &words)
	{
		int N = words.size(), count = 0;
		string res = words[0];
		for (auto &word : words)
		{
			if (!sameDiff(words[0], word))
			{
				if (++count == 2)
					return words[0];
				res = word;
			}
		}
		return res;
	}

	bool sameDiff(string &lhs, string &rhs)
	{
		int N = lhs.size();
		for (int i = 0; i < N - 1; ++i)
		{
			if (lhs[i + 1] - lhs[i] != rhs[i + 1] - rhs[i])
				return false;
		}
		return true;
	}
};