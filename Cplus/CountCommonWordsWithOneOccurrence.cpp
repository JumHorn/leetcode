#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int countWords(vector<string> &words1, vector<string> &words2)
	{
		unordered_map<string, int> m1, m2; //{str,count}
		for (auto &str : words1)
			++m1[str];
		for (auto &str : words2)
			++m2[str];
		int res = 0;
		for (auto &str : words1)
		{
			if (m1[str] == 1 && m2[str] == 1)
				++res;
		}
		return res;
	}
};