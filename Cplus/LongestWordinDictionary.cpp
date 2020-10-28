#include <algorithm>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string longestWord(vector<string> &words)
	{
		sort(words.begin(), words.end(), *this);
		int N = words.size();
		set<string> s = {""}, next_s;
		string res;
		for (int size = 1, i = 0; !s.empty(); ++size)
		{
			res = *s.begin();
			for (; i < N && words[i].length() == size; ++i)
			{
				if (s.find(words[i].substr(0, size - 1)) != s.end())
					next_s.insert(words[i]);
			}
			s.swap(next_s);
			next_s.clear();
		}
		return res;
	}

	bool operator()(string &lhs, string &rhs)
	{
		return lhs.length() < rhs.length();
	}
};