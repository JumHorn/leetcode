#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int wordCount(vector<string> &startWords, vector<string> &targetWords)
	{
		unordered_set<int> s;
		for (auto &w : startWords)
		{
			int mask = 0;
			for (auto c : w)
				mask |= (1 << (c - 'a'));
			s.insert(mask);
		}
		int res = 0;
		for (auto &w : targetWords)
		{
			int mask = 0;
			for (auto c : w)
				mask |= (1 << (c - 'a'));
			for (int i = 0; i < 26; ++i)
			{
				if (((mask >> i) & 1) && s.count(mask ^ (1 << i)) != 0)
				{
					++res;
					break;
				}
			}
		}
		return res;
	}
};