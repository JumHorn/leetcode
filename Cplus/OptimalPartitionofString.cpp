#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int partitionString(string s)
	{
		unordered_set<char> uniq;
		int res = 0;
		for (auto c : s)
		{
			if (uniq.count(c) != 0)
			{
				++res;
				uniq.clear();
			}
			uniq.insert(c);
		}
		return res + 1;
	}
};